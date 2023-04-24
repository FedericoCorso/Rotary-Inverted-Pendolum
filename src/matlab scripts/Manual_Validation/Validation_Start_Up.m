%% This script load pendulum physical (nominal) parameters in the base Workspace
clear 
close all 

nB_p = 0.0024; % Pendulum viscous damping coeffi- cient as seen at the pivot axis N*m*s/rad
nB_r = 0.0024; % Rotary arm viscous damping coeffi- cient as seen at the pivot axis N*m*s/rad
nJ_a = 0.0020; % Rotary arm moment of inertia about pivot m^2
nJ_p = 0.0012; % Pendulum moment of intertia about center of mass Kg*m^2
nl_p = 0.156;  % Distance from pivot to center of mass m
nm_p = 0.127;  % Mass of pendulum Kg
nr = 0.216;    % Rotary arm length from pivot to tip m

nJ_T = (nJ_a*nm_p*nl_p^2 + nJ_p*nm_p*nr^2 + nJ_a*nJ_p);
ng = 9.81;     % gravitational acceleration m/s^2

nK_g = 70;      % High-gear total gear ratio
nR_m = 2.6;     % Ohm
neta_g = 0.90;  % Gearbox efficiency
neta_m = 0.69;  % Motor efficiency
nk_m = 7.68e-3; % Motor back-emf constant V/(rad/s)
nk_t = 7.68e-3; % Motor current-torque constant N*m/A