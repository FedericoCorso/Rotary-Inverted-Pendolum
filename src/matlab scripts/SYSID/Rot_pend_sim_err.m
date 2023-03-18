function [err_vec,ysim] = Rot_pend_sim_err(x,z0,uin,ymeas,th,Ts,Q,scaling)
% Function that computes the output trajectory of the rotary inverted
% pendulum non linear model and the weighted error between simulated and 
% measured output. Simulation is carried out using FFD. 'x' denotes the 
% vector of decision variables, aka parameters to be identified.

%% parameters
x = x./scaling;

B_p = x(1,1);
B_r = x(2,1);
J_a = x(3,1);
J_p = x(4,1);
l_p = x(5,1);
m_p = th(6,1);
r = th(7,1);
g = th(8,1);
K_g = th(9,1);
R_m = x(6,1);
eta_g = x(7,1);
eta_m = x(8,1);
k_m = x(9,1);
k_t = x(10,1);

th = [B_p;B_r;J_a;J_p;l_p;m_p;r;g;K_g;R_m;eta_g;eta_m;k_m;k_t];

%% Run simulation with FFD
Nsim_FFD = size(ymeas,2); % number of samples 

zhat_FFD = zeros(4,Nsim_FFD); % matrix to contain the trajectories
zhat_FFD(:,1) = z0; % initial state 

for ind=2:Nsim_FFD
    zdot = NL_eqns(0,zhat_FFD(:,ind-1),uin(:,ind-1),th);
    zhat_FFD(:,ind)    =   zhat_FFD(:,ind-1)+Ts*zdot;

end

%% Run simulation with ode45
% Ts_VSS = 0.002; % 2ms
% Nsim_VSS = size(ymeas,2);% number of measured samples
% zhat_VSS = zeros(4,Nsim_VSS); % matrix to contain the trajectories
% zhat_VSS(:,1) = z0;
% 
% for ind = 1:Nsim_VSS
%     temp = ode45(@(t,z)NL_eqns(t,z,uin(:,ind),th),[0 Ts_VSS],zhat_VSS(:,ind));
%     zhat_VSS(:,ind+1) = temp.y(:,end);
% end

%% Collect simulated output (forward speed and yawrate)
% ysim = [zhat_FFD(1,:); zhat_FFD(2,:)]; % the measured output is equal to the state

ysim = zhat_FFD;
% ysim = zhat_VSS(:,end-1);
%% compute weighted error
err = Q*(ymeas-ysim);

%% stack errors in one vector
err_vec = [err(1,:) err(2,:) err(3,:) err(4,:)]'/sqrt(Nsim_FFD); % err(3,:) err(4,:)
% err_vec = [err(1,:) err(2,:)]'/sqrt(Nsim_VSS); % err(3,:) err(4,:)
end