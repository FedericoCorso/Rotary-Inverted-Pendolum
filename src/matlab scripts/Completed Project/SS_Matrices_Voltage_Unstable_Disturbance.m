function [A,B,C,D] = SS_Matrices_Voltage_Unstable_Disturbance(B_p,B_r,J_T,J_a,J_p,K_g,L_p,R_m,eta_g,eta_m,g,k_m,k_t,l_p,m_p,r)
%SS_Matrices_Voltage_Unstable_Disturbance
%    [A,B,C,D] = SS_Matrices_Voltage_Unstable_Disturbance(B_p,B_r,J_T,J_a,J_p,K_g,L_p,R_m,ETA_G,ETA_M,G,K_M,K_T,L_P,M_P,R)

%    This function was generated by the Symbolic Math Toolbox version 9.2.
%    07-May-2023 08:47:30

t2 = K_g.^2;
t3 = l_p.^2;
t4 = r.^2;
t5 = B_r.*R_m;
t6 = 1.0./J_T;
t7 = 1.0./R_m;
t8 = m_p.*t3;
t9 = m_p.*t4;
t12 = eta_g.*eta_m.*k_m.*k_t.*t2;
t10 = J_p+t8;
t11 = J_a+t9;
t13 = t5+t12;
A = reshape([0.0,0.0,0.0,0.0,0.0,0.0,g.*m_p.*r.*t6.*t8,g.*l_p.*m_p.*t6.*t11,1.0,0.0,-t6.*t7.*t10.*t13,-l_p.*m_p.*r.*t6.*t7.*t13,0.0,1.0,-B_p.*l_p.*m_p.*r.*t6,-B_p.*t6.*t11],[4,4]);
if nargout > 1
    B = reshape([0.0,0.0,K_g.*eta_g.*eta_m.*k_t.*t6.*t7.*t10,K_g.*eta_g.*eta_m.*k_t.*l_p.*m_p.*r.*t6.*t7,0.0,0.0,L_p.*l_p.*m_p.*r.*t6,L_p.*t6.*t11],[4,2]);
end
if nargout > 2
    C = reshape([1.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0],[2,4]);
end
if nargout > 3
    D = [0.0;0.0];
end