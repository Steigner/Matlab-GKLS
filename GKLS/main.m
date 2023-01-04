%% generate mex from c code

% codegen generate -args {1,2,3,4,5,6} main.c

%% call generated function

% dimensions
dim = 3;

% number of minims
num_min = 10;

% distanc / radius
dist = 2/3; 
radius = 0.5;

% number of generated files to data folder
problems = 10;

% 1: for D-type test function
% 2: for ND-type test function
% 3: for D2-type test function
test_function = 1;

% call mex generated function
error_msg = generate_mex(dim,num_min,dist,radius,problems,test_function);

switch error_msg
    case 0
        disp('GLKS OK');
    case 1
        disp('GKLS_DIM_ERROR');
    case 2
        disp('GKLS_NUM_MINIMA_ERROR');
    case 3
        disp('GKLS_FUNC_NUMBER_ERROR');
    case 4
        disp('GKLS_BOUNDARY_ERROR  ');
    case 5
        disp('GKLS_GLOBAL_MIN_VALUE_ERROR');
    case 6
        disp('GKLS_GLOBAL_DIST_ERROR');
    case 7
        disp('GKLS_GLOBAL_RADIUS_ERROR');
    case 8
        disp('GKLS_MEMORY_ERROR');
    case 9
        disp('GKLS_DERIV_EVAL_ERROR');
    case 10
        disp('GKLS_GREAT_DIM');
    case 11
        disp('GKLS_RHO_ERROR');
    case 12
        disp('GKLS_PEAK_ERROR');
    case 13
        disp('GKLS_GLOBAL_BASIN_INTERSECTION');
    case 14
        disp('GKLS_PARABOLA_MIN_COINCIDENCE_ERROR');
    case 15
        disp('GKLS_LOCAL_MIN_COINCIDENCE_ERROR');
    case 16
        disp('GKLS_FLOATING_POINT_ERROR');
    otherwise
        disp('!! Uncaught error !!')
end