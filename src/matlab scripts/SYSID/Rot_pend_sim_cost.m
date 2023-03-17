function [cost,ysim] = Rot_pend_sim_cost(x,z0,uin,ymeas,th,Ts,Q,scaling)

[err_vec,ysim]    =   Rot_pend_sim_err(x,z0,uin,ymeas,th,Ts,Q,scaling);

%% Compute sum of squared errors
cost    =   sum(err_vec.*err_vec);
end