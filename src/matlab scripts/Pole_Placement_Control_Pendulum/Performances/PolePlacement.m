clear 
close all 
close all

% LE ULTIME 3 RIGHE FANNO TUTTO DA SOLE (per trovare il K del pole placem.)

parametri = 1;      % 0 = nominali; 1 = identificati

%% System parameters
if parametri == 0
    B_p = 0.0024; % Pendulum viscous damping coeffi- cient as seen at the pivot axis N*m*s/rad
    B_r = 0.0024; % Rotary arm viscous damping coeffi- cient as seen at the pivot axis N*m*s/rad
    J_a = 0.0020; % Rotary arm moment of inertia about pivot m^2
    J_p = 0.0012; % Pendulum moment of intertia about center of mass Kg*m^2
    l_p = 0.156;  % Distance from pivot to center of mass m
    m_p = 0.127;  % Mass of pendulum Kg
    r = 0.216;    % Rotary arm length from pivot to tip m
    J_T = (J_a*m_p*l_p^2 + J_p*m_p*r^2 + J_a*J_p);
    g = 9.81;     % gravitational acceleration m/s^2

    K_g = 70;      % High-gear total gear ratio
    R_m = 2.6;     % Ohm
    eta_g = 0.90;  % Gearbox efficiency
    eta_m = 0.69;  % Motor efficiency
    k_m = 7.68e-3; % Motor back-emf constant V/(rad/s)
    k_t = 7.68e-3; % Motor current-torque constant N*m/A
else
    % Valori identificati
    load th_id
    B_p = id_param(1); % Pendulum viscous damping coeffi- cient as seen at the pivot axis N*m*s/rad
    B_r = id_param(2); % Rotary arm viscous damping coeffi- cient as seen at the pivot axis N*m*s/rad
    J_a = id_param(3); % Rotary arm moment of inertia about pivot m^2
    J_p = id_param(4); % Pendulum moment of intertia about center of mass Kg*m^2
    l_p = id_param(5);  % Distance from pivot to center of mass m
    m_p = id_param(6);  % Mass of pendulum Kg
    r = id_param(7);    % Rotary arm length from pivot to tip m
    J_T = (J_a*m_p*l_p^2 + J_p*m_p*r^2 + J_a*J_p);
    g = id_param(8);     % gravitational acceleration m/s^2

    K_g = id_param(9);      % High-gear total gear ratio
    R_m = id_param(10);     % Ohm
    eta_g = id_param(11);  % Gearbox efficiency
    eta_m = id_param(12);  % Motor efficiency
    k_m = id_param(13); % Motor back-emf constant V/(rad/s)
    k_t = id_param(14); % Motor current-torque constant N*m/A
end

% Filter Parameters:
% High-pass filter used to compute velocity
wcf_1 = 2 * pi * 10.0; % Cutoff frequency (rad/s)
% Pendulum High-pass filter used to compute velocity
wcf_2 = 2 * pi * 10.0; % Cutoff frequency (rad/s)

%% Control design and time responce requirement:
zeta = 0.7;         % Damping ratio
ome_n = 4;          % Natural frequency [rad/s]

theta_max = 45;     % Maximum theta rotation[deg]
alpha_max = 15;     % Maximum alpha deflection [deg]
voltage_max = 6;    % Maximum control voltage

% zeta and ome_n gives the necessary closed loop poles
% alpha_max and voltage_max are to be satisfy when the rotating arm is
% traking a +-20 deg angle squared wave

%% Build the state space matrices
[A,B,C,D] = SS_Matrices_Voltage_Unstable(B_p,B_r,J_T,J_a,J_p,K_g,R_m,eta_g,eta_m,g,k_m,k_t,l_p,m_p,r);
C = eye(4);
D = zeros(4,1);

% State-space model
ss_sys = ss(A,B,C,D);

% Transfer functions
tf_sys = tf(ss_sys);

[wn, zeta, p] = damp(ss_sys);

eigenvalues = eig(A); % = the system is unstable

% Characterist equation
syms s
p = poly(A);
polinomial_equation = p(1)*s^4 + p(2)*s^3 + p(3)*s^2 + p(4)*s^1 + p(5)*s^0;

% Controllability matrix T = [B AB A^2B...A^nB]
T = ctrb(ss_sys);
n = rank(T);                % The rank of the T is 4 = #states => sys is controllable

% Controllable canonical form
A_hat = [   0       1       0       0;
            0       0       1       0;
            0       0       0       1;
            -p(5)   -p(4)   -p(3)   -p(2)]; % Companion matrix A
B_hat = [ 0; 0; 0; 1];          % Companion matrix B                  
T_hat = ctrb(A_hat,B_hat);      % Companion matrix T

% Control tests (not necessary, but works) 
W = T*inv(T_hat);
% A_hat_check = inv(W)*A*W;
% B_hat_check = inv(W)*B;

%% Pole palcement
% control law: u = -Kx; now we design K (for a controllable sys):

% Desired poles:
sigma = zeta*ome_n;
ome_d = ome_n*sqrt(1-zeta^2); % damped natuaral frequency
i = sqrt(-1);   % immaginary unit
p1 = -sigma + i*ome_d;
p2 = -sigma - i*ome_d;
p3 = -30;
p4 = -40;
characteristic_polynomial = collect(simplify((s-p1)*(s-p2)*(s-p3)*(s-p4)),s);
p_d = coeffs(characteristic_polynomial); % desired poles

k1 = p_d(1);
k2 = double(p_d(2) - p(4));
k3 = double(p_d(3) - p(3));
k4 = double(p_d(4) - p(2));
K_hat = double([ k1 k2 k3 k4 ]);    
K = K_hat*inv(W)           % Balance control gain

% Closed loop poles
eig(A-B*K);  % Equivalent to the location og the desired poles


% Compensator Design Matlab command = find K using a Matlab pole palcement
% sigma = zeta*ome_n;
% ome_d = ome_n*sqrt(1-zeta^2); % damped natuaral frequency
% DP = [ -sigma+i*ome_d, -sigma-i*ome_d, -30, -40];
% K = acker(A,B,DP);




















