function [f,zsim] = Pendulum_cost_constr(U,z0,Ts,Q,R,Qf,usat,xsat,alpha,beta,parameters)

N=length(U);

zsim        =   zeros(4*(N+1),1);
zsim(1:4,1) =   z0;
ztemp       =   z0;

F           =   [zeros(4*N,1);
                zeros(4,1);
                Qf*U(N,1);
                R*U;
                alpha*exp(-beta*(usat+U));
                alpha*exp(-beta*(usat-U));
                zeros(2*N,1)];

for ind=2:N+1
    % Update the state
    [zdot]                              =   NL_eqns(0,ztemp,...
                                                U(ind-1,1),parameters);   
    ztemp                               =   ztemp+Ts*zdot;
    zsim((ind-1)*4+1:ind*4,1)           =   ztemp;
    
    % Update the cost function
    F((ind-2)*4+1:(ind-1)*4,1)          =   Q*[ztemp(3,1);sin(ztemp(2,1)/2);ztemp(3,1);ztemp(4,1)];
    F(7*N+5+ind-1,1)                    =   alpha*exp(-beta*(xsat+zsim((ind-1)*4+1,1)));
    F(8*N+5+ind-1,1)                    =   alpha*exp(-beta*(xsat-zsim((ind-1)*4+1,1)));
end

% Update the terminal cost
F(4*N+1:4*N+4,:)                =   Qf*[zsim(end-3,1);sin(zsim(end-1,1)/2);zsim(end-2,1);zsim(end,1)];
f=F'*F;


    

