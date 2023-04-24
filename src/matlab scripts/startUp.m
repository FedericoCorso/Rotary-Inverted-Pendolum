%% This script load pendulum physical parameters in the base Workspace
clear 
close all 

% from  file: 04_InvertedPendulum_UserManual.pdf
B_p = 2.4e-3; % Pendulum viscous damping coeffi- cient as seen at the pivot axis N*m*s/rad
B_r = 2.4e-3; % Rotary arm viscous damping coeffi- cient as seen at the pivot axis N*m*s/rad
J_a = 2.0e-3; % Rotary arm moment of inertia about pivot m^2
J_p = 1.2e-3; % Pendulum moment of intertia about center of mass Kg*m^2
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

% store all the parameters in a vector
th = [B_p;B_r;J_a;J_p;l_p;m_p;r;g;K_g;R_m;eta_g;eta_m;k_m;k_t];