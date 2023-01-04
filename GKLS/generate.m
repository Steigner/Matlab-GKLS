function [error_msg] = generate(dim,num_min, global_dist, global_radius, num_problems, test_function)
    %#codegen
    error_msg = 0;
    coder.cinclude('rnd_gen.h');
    coder.cinclude('gkls.h');
    coder.cinclude('gkls.c');
    coder.cinclude('rnd_gen.c');
    % generate an include in the C code
    coder.cinclude('main.h');
    % evaluate the C function
    error_msg = coder.ceval('main', dim, num_min, global_dist, global_radius, num_problems, test_function);
end