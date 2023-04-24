
clear all
close all 

% from  file: 04_InvertedPendulum_UserManual.pdf
B_p = 0.0024; % Pendulum viscous damping coeffi- cient as seen at the pivot axis N*m*s/rad
B_r = 0.0024; % Rotary arm viscous damping coeffi- cient as seen at the pivot axis N*m*s/rad
J_a = 0.0020; % Rotary arm moment of inertia about pivot m^2
J_p = 0.0012; % Pendulum moment of intertia about center of mass Kg*m^2
l_p = 0.156;  % Distance from pivot to center of mass m
m_p = 0.127;  % Mass of pendulum Kg
r = 0.216;    % Rotary arm length from pivot to tip m
J_T = (J_a*m_p*l_p^2 + J_p*m_p*r^2 + J_a*J_p);
g = 9.81;     % gravitational acceleration m/s^2

% from file: 03_ServoBaseUnit_UserManual.pdf
K_g = 70;      % High-gear total gear ratio
R_m = 2.6;     % Ohm
eta_g = 0.90;  % Gearbox efficiency
eta_m = 0.69;  % Motor efficiency
k_m = 7.68e-3; % Motor back-emf constant V/(rad/s)
k_t = 7.68e-3; % Motor current-torque constant N*m/A

%this is a mistake (result is different)
Sig_1 = eta_g*eta_m*k_m*k_t*K_g^2 + B_r*R_m;
Sig_2 = m_p*r^2 + J_a;
B1 = K_g*eta_g*eta_m*k_t*(m_p*l_p^2+J_p);
B2 = K_g*eta_g*eta_m*k_t*m_p*l_p*r;
%G = tf([(g*l_p*Sig_2*B2) (((J_T*R_m*g*l_p^2*m_p^2*r*B1)-(g*l_p^3*m_p^3*r*Sig_1+(m_p*l_p^2+J_p)*Sig_1*g*l_p*m_p*Sig_2)*B2)/(J_T*R_m)) 0],[(J_T^2*R_m) ((B_p*Sig_2*J_T*R_m+(m_p*l_p^2+J_p)*Sig_1*J_T)) ((m_p*l_p^2+J_p)*Sig_1*B_p*Sig_2-B_p*l_p^2*m_p^2*r^2*Sig_1-g*l_p*m_p*Sig_2*J_T*R_m) (g*l_p^3*m_p^3*r^2*Sig_1-g*l_p*m_p*Sig_2*Sig_1*(m_p*l_p^2+J_p)) 0])

%Transfert function and analysis
A = [0 0 1 0; 0 0 0 1; 0 (g*l_p^2*m_p^2*r)/J_T -((m_p*l_p^2+J_p)*(eta_g*eta_m*k_m*k_t*K_g^2+B_r*R_m))/(J_T*R_m) -(B_p*l_p*m_p*r)/J_T; 0 (g*l_p*m_p*(m_p*r^2+J_a))/J_T -(l_p*m_p*r*(eta_g*eta_m*k_m*k_t*K_g^2+B_r*R_m))/(J_T*R_m) -(B_p*(m_p*r^2+J_a))/J_T];
B = [0; 0; (K_g*eta_g*eta_m*k_t*(m_p*l_p^2+J_p))/(J_T*R_m); (K_g*eta_g*eta_m*k_t*l_p*m_p*r)/(J_T*R_m)];
C = [1 0 0 0; 0 1 0 0];
D = [0; 0];
sys=ss(A,B,C,D);

G = tf(sys); %find complete TF Matrix
G_1 = G(1) %First TF
G_2 = G(2) %Second TF

P_1 = eig(G_1) %find poles
P_2 = eig(G_2)

[Z_1,gain_1] = zero(G_1)%find zeroes and gain
[Z_2,gain_2] = zero(G_2)

bode(G)

nyquist(G); 
% modelReducer(G_1)
% modelReducer(G_2)
freqresp(G);
[Gm1,Pm1,Wcg1,Wcp1] = margin(G_1)
[Gm2,Pm2,Wcg2,Wcp2] = margin(G_2)

