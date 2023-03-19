function [x_dot,y] = rot_pend_m(t,x,V_m,B_p,B_r,J_a,J_p,l_p,m_p,r,g,K_g,R_m,eta_g,eta_m,k_m,k_t,varargin)
%NL_eqns
%    NL_DIFF_EQNS_SS = NL_eqns(B_p,th(2,1),J_a,J_p,G,L_P,M_P,R,TAU,x(2,1),x(3,1),x(4,1),X_DOT_1,X_DOT_2,X_DOT_3,X_DOT_4)

%    This function was generated by the Symbolic Math Toolbox version 9.2.
%    09-Mar-2023 15:34:15

y = [x(1);x(2)];

x_dot = [x(3);
         x(4);
         -(2*sin(2*x(2))*l_p^4*m_p^2*x(3)*x(4) - r*sin(2*x(2))*cos(x(2))*l_p^3*m_p^2*x(3)^2 + 2*r*sin(x(2))*l_p^3*m_p^2*x(4)^2 - 2*g*r*cos(x(2))*sin(x(2))*l_p^2*m_p^2 + 2*J_p*sin(2*x(2))*l_p^2*m_p*x(3)*x(4) + 2*B_r*l_p^2*m_p*x(3) - 2*(eta_g*K_g*eta_m*k_t*(V_m-K_g*k_m*x(3))/R_m)*l_p^2*m_p + 2*J_p*r*sin(x(2))*l_p*m_p*x(4)^2 + 2*B_p*r*cos(x(2))*l_p*m_p*x(4) + 2*B_r*J_p*x(3) - 2*J_p*(eta_g*K_g*eta_m*k_t*(V_m-K_g*k_m*x(3))/R_m))/(2*(J_a*J_p + l_p^4*m_p^2 - l_p^4*m_p^2*cos(x(2))^2 + l_p^2*m_p^2*r^2 + J_a*l_p^2*m_p + J_p*l_p^2*m_p + J_p*m_p*r^2 - l_p^2*m_p^2*r^2*cos(x(2))^2 - J_p*l_p^2*m_p*cos(x(2))^2));
         -(2*B_p*J_a*x(4) - l_p^4*m_p^2*x(3)^2*sin(2*x(2)) - 2*g*l_p^3*m_p^2*sin(x(2)) + 2*B_p*l_p^2*m_p*x(4) + 2*B_p*m_p*r^2*x(4) - J_a*l_p^2*m_p*x(3)^2*sin(2*x(2)) + l_p^4*m_p^2*x(3)^2*sin(2*x(2))*cos(x(2))^2 + 2*g*l_p^3*m_p^2*cos(x(2))^2*sin(x(2)) - 2*B_p*l_p^2*m_p*x(4)*cos(x(2))^2 - 2*g*l_p*m_p^2*r^2*sin(x(2)) - 2*J_a*g*l_p*m_p*sin(x(2)) - l_p^2*m_p^2*r^2*x(3)^2*sin(2*x(2)) - 2*l_p*m_p*r*(eta_g*K_g*eta_m*k_t*(V_m-K_g*k_m*x(3))/R_m)*cos(x(2)) + 2*B_r*l_p*m_p*r*x(3)*cos(x(2)) + 2*l_p^2*m_p^2*r^2*x(4)^2*cos(x(2))*sin(x(2)) + 2*l_p^3*m_p^2*r*x(3)*x(4)*sin(2*x(2))*cos(x(2)))/(2*(J_a*J_p + l_p^4*m_p^2 - l_p^4*m_p^2*cos(x(2))^2 + l_p^2*m_p^2*r^2 + J_a*l_p^2*m_p + J_p*l_p^2*m_p + J_p*m_p*r^2 - l_p^2*m_p^2*r^2*cos(x(2))^2 - J_p*l_p^2*m_p*cos(x(2))^2))];
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               