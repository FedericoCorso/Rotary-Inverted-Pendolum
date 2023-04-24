% clear 
close all 
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

% Filter Parameters:
% High-pass filter used to compute velocity
wcf_1 = 2 * pi * 10.0; % Cutoff frequency (rad/s)
% Pendulum High-pass filter used to compute velocity
wcf_2 = 2 * pi * 10.0; % Cutoff frequency (rad/s)

theta_max = 60;     % Maximum theta rotation[deg]
% alpha_max = 15;     % Maximum alpha deflection [deg]
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
G_s = tf_sys(1)

% controlSystemDesigner(G_s)

% Poli
p = eig(tf_sys(1));
% Gain margin, Phase margin, corresponding frequences
[Gm1,Pm1,Wcg1,Wcp1] = margin(tf_sys(1));

% R_s = ((1+0.062*s)*(1 + 0.011s + (0.15s)^2))/((1 + 0.01s) (1 + 0.018s + (0.15s)^2))
% NumR_s = tf([0.062 1],[1])*tf([0.15 0.011 1],[1]); % cancel complex poles of G(s)
% Den_R_s = tf([0.15 0.018 1],[1]);% to cancel zeros of G(s)
% gain_R = 4;
% Den_R_s_2 = tf([0.01 1],[1]);
% R_s = gain_R*((NumR_s)/(Den_R_s_2*Den_R_s))

%% PID tuner

% pidTuner(ss_sys(1),'p')

% Compute the gain for the PID controller
opts = pidtuneOptions('CrossoverFrequency',BW,'PhaseMargin',PM);
[G, info] = pidtune(ss_sys(1), type, opts);
% [G, info] = pidtune(tf_sys(1), type, opts);
Kp = G.Kp;      % Proportional gain
Ki = G.Ki;      % Integral gain
Kd = G.Kd;      % Derivative gain



