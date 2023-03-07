startUp

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
