function F_eval = computeFJacobian(Ts,x1_k,x2_k,x3_k,x4_k,V_m,th)
%computeFJacobian
%    F_eval = computeFJacobian(Ts,X1_K,X2_K,X3_K,X4_K,V_m,B_p,B_r,J_a,J_p,L_P,M_P,R,G,K_g,R_m,ETA_G,ETA_M,K_M,K_T)

%    This function was generated by the Symbolic Math Toolbox version 9.2.
%    18-May-2023 15:21:46

% B_p,B_r,J_a,J_p,l_p,m_p,r,g,K_g,R_m,eta_g,eta_m,k_m,k_t

B_p = th(1,1);
B_r = th(2,1);
J_a = th(3,1);
J_p = th(4,1);
l_p = th(5,1);
m_p = th(6,1);
r = th(7,1);
g = th(8,1);
K_g = th(9,1);
R_m = th(10,1);
eta_g = th(11,1);
eta_m = th(12,1);
k_m = th(13,1);
k_t = th(14,1);


t2 = cos(x2_k);
t3 = sin(x2_k);
t4 = K_g.^2;
t5 = l_p.^2;
t6 = l_p.^3;
t8 = m_p.^2;
t9 = r.^2;
t10 = x2_k.*2.0;
t11 = x2_k.*3.0;
t12 = x3_k.^2;
t13 = x4_k.^2;
t14 = J_a.*J_p;
t20 = 1.0./R_m;
t7 = t5.^2;
t15 = cos(t10);
t16 = cos(t11);
t17 = t2.^2;
t18 = sin(t10);
t19 = t3.^2;
t21 = m_p.*t5;
t22 = m_p.*t9;
t29 = t5.*t8.*t9;
t23 = J_a.*t21;
t24 = J_p.*t21;
t25 = J_p.*t22;
t26 = t19-1.0;
t27 = t7.*t8;
t32 = J_p+t21+t22;
t34 = t17.*t29;
t28 = t17.*t24;
t30 = t17.*t27;
t35 = -t34;
t31 = -t28;
t33 = -t30;
t36 = t14+t23+t24+t25+t27+t29+t31+t33+t35;
t37 = 1.0./t36;
t38 = t37.^2;
et1 = -(Ts.*l_p.*m_p.*(J_p.*r.*t2.*t13.*4.0-r.*t2.*t12.*t21+r.*t2.*t13.*t21.*4.0-r.*t12.*t16.*t21.*3.0-B_p.*r.*t3.*x4_k.*4.0+J_p.*l_p.*t15.*x3_k.*x4_k.*8.0-g.*l_p.*m_p.*r.*t15.*4.0+m_p.*t6.*t15.*x3_k.*x4_k.*8.0))./(t14.*4.0+t23.*4.0+t24.*2.0+t25.*4.0+t27.*2.0+t29.*2.0-t15.*t24.*2.0-t15.*t27.*2.0-t15.*t29.*2.0);
et2 = (Ts.*t18.*t21.*t32.*t38.*(B_r.*J_p.*x3_k.*2.0+B_r.*t21.*x3_k.*2.0+t18.*t24.*x3_k.*x4_k.*2.0+t18.*t27.*x3_k.*x4_k.*2.0-g.*r.*t5.*t8.*t18+r.*t3.*t6.*t8.*t13.*2.0+r.*t3.*t6.*t8.*t12.*t26.*2.0+B_p.*l_p.*m_p.*r.*t2.*x4_k.*2.0+J_p.*l_p.*m_p.*r.*t3.*t13.*2.0-K_g.*V_m.*eta_g.*eta_m.*k_t.*t20.*t21.*2.0-J_p.*K_g.*V_m.*eta_g.*eta_m.*k_t.*t20.*2.0+J_p.*eta_g.*eta_m.*k_m.*k_t.*t4.*t20.*x3_k.*2.0+eta_g.*eta_m.*k_m.*k_t.*t4.*t20.*t21.*x3_k.*2.0))./2.0;
et3 = (Ts.*l_p.*m_p.*t20.*(R_m.*g.*t2.*t21.*3.0+R_m.*g.*t2.*t22.*4.0-R_m.*g.*t16.*t21.*3.0+J_a.*R_m.*g.*t2.*4.0-R_m.*m_p.*t6.*t12.*cos(x2_k.*4.0).*2.0-B_p.*R_m.*l_p.*t18.*x4_k.*4.0+J_a.*R_m.*l_p.*t12.*t15.*4.0+B_r.*R_m.*r.*t3.*x3_k.*4.0+R_m.*l_p.*t12.*t15.*t22.*4.0-R_m.*l_p.*t13.*t15.*t22.*4.0+R_m.*m_p.*t6.*t12.*t15.*2.0-R_m.*r.*t2.*t21.*x3_k.*x4_k.*2.0-R_m.*r.*t16.*t21.*x3_k.*x4_k.*6.0-K_g.*V_m.*eta_g.*eta_m.*k_t.*r.*t3.*4.0+eta_g.*eta_m.*k_m.*k_t.*r.*t3.*t4.*x3_k.*4.0))./(t14.*4.0+t23.*4.0+t24.*2.0+t25.*4.0+t27.*2.0+t29.*2.0-t15.*t24.*2.0-t15.*t27.*2.0-t15.*t29.*2.0);
et4 = Ts.*t18.*t21.*t32.*t38.*(B_p.*J_a.*x4_k.*-2.0-B_p.*t21.*x4_k.*2.0-B_p.*t22.*x4_k.*2.0+t12.*t18.*t23+t12.*t18.*t27+t12.*t18.*t29-t13.*t18.*t29+B_p.*t17.*t21.*x4_k.*2.0+g.*t3.*t6.*t8.*2.0-t2.^3.*t3.*t12.*t27.*2.0-g.*t6.*t8.*(t3-t3.^3).*2.0+J_a.*g.*l_p.*m_p.*t3.*2.0+g.*l_p.*t3.*t8.*t9.*2.0-B_r.*l_p.*m_p.*r.*t2.*x3_k.*2.0+r.*t3.*t6.*t8.*t26.*x3_k.*x4_k.*4.0+K_g.*eta_g.*eta_m.*k_t.*l_p.*m_p.*r.*t2.*t20.*(V_m-K_g.*k_m.*x3_k).*2.0).*(-1.0./2.0);
mt1 = [1.0,0.0,0.0,0.0,0.0,1.0,et1+et2,et3+et4,Ts,0.0,Ts.*t37.*(B_r.*t21.*2.0+B_r.*J_p.*2.0+t18.*t24.*x4_k.*2.0+t18.*t27.*x4_k.*2.0-r.*t2.*t6.*t8.*t18.*x3_k.*2.0+J_p.*eta_g.*eta_m.*k_m.*k_t.*t4.*t20.*2.0+eta_g.*eta_m.*k_m.*k_t.*t4.*t20.*t21.*2.0).*(-1.0./2.0)+1.0,Ts.*t37.*(t18.*t23.*x3_k.*-2.0-t18.*t27.*x3_k.*2.0-t18.*t29.*x3_k.*2.0+t18.*t30.*x3_k.*2.0+B_r.*l_p.*m_p.*r.*t2.*2.0+r.*t2.*t6.*t8.*t18.*x4_k.*2.0+eta_g.*eta_m.*k_m.*k_t.*l_p.*m_p.*r.*t2.*t4.*t20.*2.0).*(-1.0./2.0),0.0,Ts,-Ts.*l_p.*m_p.*t37.*(B_p.*r.*t2+J_p.*l_p.*t18.*x3_k+J_p.*r.*t3.*x4_k.*2.0+m_p.*t6.*t18.*x3_k+r.*t3.*t21.*x4_k.*2.0)];
mt2 = [Ts.*t37.*(B_p.*t21.*2.0+B_p.*t22.*2.0+B_p.*J_a.*2.0-B_p.*t17.*t21.*2.0+t2.*t3.*t29.*x4_k.*4.0+r.*t3.*t6.*t8.*t17.*x3_k.*4.0).*(-1.0./2.0)+1.0];
F_eval = reshape([mt1,mt2],4,4);