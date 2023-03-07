clear 
close all 

% to check also the phd thesis on the control of the inverted pendolum to
% find the problem with the values of our matrices.

%% model parameters
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

%% build the state space matrices
[A,B,C,D] = SS_Matrices(B_p,B_r,J_T,J_a,J_p,K_g,R_m,eta_g,eta_m,g,k_m,k_t,l_p,m_p,r);
% State-space model
system = ss(A,B,C,D);

system.A
system.B
system.C
system.D

% eigenvalues of the system
eig(A)


%% simulation of the NL equations - Variable Step solver
x0 = [0;pi/2;0;0];

% Time integration parameters
Ts_VSS      =       0.001;              % sampling time (s)
Tend_VSS    =       5;                  % final time (s)
tsim_VSS    =       0:Ts_VSS:Tend_VSS;  % time vector (s)
Nsim_VSS = Tend_VSS/Ts_VSS; 

xsim_VSS = zeros(4,Nsim_VSS+1); % matrix to contain the trajectories
xsim_VSS(:,1) = x0; % initial state init

ubar = 0; % Volt

% Run simulation
tic
for ind=1:Nsim_VSS
     temp = ode45(@(t,x)NL_eqns(t,x,ubar,B_p,B_r,J_a,J_p,g,l_p,m_p,r,K_g,R_m,eta_g,eta_m,k_m,k_t),[0 Ts_VSS],xsim_VSS(:,ind));
     % [0 Ts_VSS] with this argument we solve only for one time step
     xsim_VSS(:,ind+1) = temp.y(:,end); % value of the state at sampling time, so at the last step of solver, for next iteration
end
toc

figure(1)
plot(tsim_VSS,xsim_VSS(1,:)); grid on % theta angle
title("\theta");
figure(2)
plot(tsim_VSS,xsim_VSS(2,:));grid on % alpha angle
title("\alpha");
figure(3)
plot(tsim_VSS,xsim_VSS(3,:));grid on% theta_dot
title("theta dot");
figure(4)
plot(tsim_VSS,xsim_VSS(4,:));grid on % alpha_dot
title("alpha dot");
