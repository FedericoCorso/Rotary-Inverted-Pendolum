%% simulation of the NL equations - Variable Step solver

startUp

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