
tic();

// Load simulation parameters
mprintf('*******************************************************\n');
mprintf('** PMSM motor sensorless FOC cloesed loop simulation\n');
mprintf('*******************************************************\n');
importXcosDiagram("mc_foc_sl_fip_dspic33ck_mclv48v300w_Melody.zcos");
mprintf('** Model loaded!\n');

if isfile("gen_inputs.sce") then
    exec("gen_inputs.sce", -1);
    mprintf("Simulation input loaded.\n")
end

mprintf('** Simulation started!\n');
xcos_simulate(scs_m, 4);
mprintf('** Simulation finished!\n');
w=getdate()
mprintf("** Simulation date: %d.%d.%d\n",w(2),w(6),w(1));
mprintf("** Simulation time: %d:%d:%d\n",w(7),w(8),w(9));
exec('save_simulation.sce');    // safe simulation results
mprintf('** Simulation data saved!\n');
exec('show_simulation.sce');    // show simulation results

simulation_time = toc()/60;

mprintf('** sim_step = %1.6f s\n',sim_step);
mprintf('** sim_buffer = %d [1]\n',sim_buffer);
mprintf('** simulation time = %3.2f min\n',simulation_time);
mprintf('*******************************************************\n');
