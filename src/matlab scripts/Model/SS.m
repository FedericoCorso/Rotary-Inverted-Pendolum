startUp

close all

%% build the state space matrices
[A,B,C,D] = SS_Matrices_Voltage_Stable(B_p,B_r,J_T,J_a,J_p,K_g,R_m,eta_g,eta_m,g,k_m,k_t,l_p,m_p,r);
% [A,B,C,D] = SS_Matrices_Voltage_Unstable(B_p,B_r,J_T,J_a,J_p,K_g,R_m,eta_g,eta_m,g,k_m,k_t,l_p,m_p,r);
% [A,B,C,D] = SS_Matrices_Torque_Stable(B_p,B_r,J_T,J_a,J_p,g,l_p,m_p,r);
% [A,B,C,D] = SS_Matrices_Torque_Unstable(B_p,B_r,J_T,J_a,J_p,g,l_p,m_p,r);
C = eye(4);
D = zeros(4,1);
% State-space model
ss_sys = ss(A,B,C,D);

ss_sys.A
ss_sys.B
ss_sys.C
ss_sys.D

% Transfer functions
tf_sys = tf(ss_sys);
tf_sys(1)

% eigenvalues of the system
eigenvalues = eig(A);

% bandwidth(system)
w = 0:0.001:1000;
[mag,phase,wout] = bode(ss_sys,w);

% conversion to logarithm scale
mag_theta = 20*log10(mag(1,:));
mag_alpha = 20*log10(mag(2,:));
mag_theta_dot = 20*log10(mag(3,:));
mag_alpha_dot = 20*log10(mag(4,:));

% separated bode plots
figure
semilogx(w,mag_theta),grid on
figure
semilogx(w,mag_alpha),grid on
figure
semilogx(w,mag_theta_dot),grid on
figure
semilogx(w,mag_alpha_dot),grid on

bandwidth_theta_dot = wout(4180,1);


