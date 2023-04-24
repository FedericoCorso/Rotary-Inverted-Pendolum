

clear 
close all 

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

theta_max = 90;     % +- Maximum theta rotation [deg]
voltage_max = 10;   % Maximum control voltage

%% PID tuner settings
type = 'pi';        % Opzioni: p pi pid
BW = 4.04;          % Bandwidth
PM = 90;            % Phase Margin

%% Build the state space matrices
[A,B,C,D] = SS_Matrices_Voltage_Stable(B_p,B_r,J_T,J_a,J_p,K_g,R_m,eta_g,eta_m,g,k_m,k_t,l_p,m_p,r);
C = eye(4);
D = zeros(4,1);

% State-space model
ss_sys = ss(A,B,C,D);

% Transfer functions
tf_sys = tf(ss_sys);

% controlSystemDesigner(tf_sys(1))

%% PID tuner

% pidTuner(ss_sys(1),'p')

% Compute the gain for the PID controller
opts = pidtuneOptions('CrossoverFrequency',BW,'PhaseMargin',PM);
[G, info] = pidtune(ss_sys(1), type, opts);
% [G, info] = pidtune(tf_sys(1), type, opts);
Kp = G.Kp;      % Proportional gain
Ki = G.Ki;      % Integral gain
Kd = G.Kd;      % Derivative gain

%% Compensators
% controlSystemDesigner(tf_sys(1))
% Strictly proper

% ~ Alberto
% Overshoot of 3.5%, settling time 0.131, rise time 0.032
R1 = zpk([-15 -40],[-55 -60],143); % Nel toolbox gain = 26
L1 = R1*tf_sys(1)/(1+R1*tf_sys(1));
step(L1); grid on; title('R_1 Step Responce')
stepinfo(L1);

% ~ Alberto
% % Overshoot of 0%, settling time 0.474, rise time 0.0217
R2 = zpk([-7 -50],[-70 -60],96); % Nel toolbox gain = 8
L2 = R2*tf_sys(1)/(1+R2*tf_sys(1));
% step(L2); grid on; title('R_2 Step Responce')
stepinfo(L2);

% ~ Simone
R3 = zpk((-3e7/1.5e6),(-100000),1.5e6);
L3 = R3*tf_sys(1)/(1+R3*tf_sys(1));
% step(L3); grid on; title('R_3 Step Responce')
stepinfo(L3);

% ~ Federico
load('Reg_Fede.mat');
R4 = R;
L4 = R4*tf_sys(1)/(1+R4*tf_sys(1));
% step(L4); grid on; title('R_4 Step Responce')
stepinfo(L4);

% [Gm1,Pm1,Wcg1,Wcp1] = margin(R4*tf_sys(1))




