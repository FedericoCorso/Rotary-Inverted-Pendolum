function [A,B,C,D] = SS_Matrices_Torque_Unstable(B_p,B_r,J_T,J_a,J_p,g,l_p,m_p,r)
%SS_Matrices_Torque_Unstable
%    [A,B,C,D] = SS_Matrices_Torque_Unstable(B_p,B_r,J_T,J_a,J_p,G,L_P,M_P,R)

%    This function was generated by the Symbolic Math Toolbox version 9.2.
%    09-Mar-2023 15:56:26

t2 = l_p.^2;
t3 = r.^2;
t4 = 1.0./J_T;
t5 = m_p.*t2;
t6 = m_p.*t3;
t7 = J_p+t5;
t8 = J_a+t6;
A = reshape([0.0,0.0,0.0,0.0,0.0,0.0,g.*m_p.*r.*t4.*t5,g.*l_p.*m_p.*t4.*t8,1.0,0.0,-B_r.*t4.*t7,-B_r.*l_p.*m_p.*r.*t4,0.0,1.0,-B_p.*l_p.*m_p.*r.*t4,-B_p.*t4.*t8],[4,4]);
if nargout > 1
    B = [0.0;0.0;t4.*t7;l_p.*m_p.*r.*t4];
end
if nargout > 2
    C = reshape([1.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0],[2,4]);
end
if nargout > 3
    D = [0.0;0.0];
end
