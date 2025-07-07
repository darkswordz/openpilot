#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_3316257012826674087);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2057247982490778565);
void pose_H_mod_fun(double *state, double *out_4138089403229407673);
void pose_f_fun(double *state, double dt, double *out_7388093933502948823);
void pose_F_fun(double *state, double dt, double *out_5999254502567580570);
void pose_h_4(double *state, double *unused, double *out_1537498951801424975);
void pose_H_4(double *state, double *unused, double *out_863867324438458420);
void pose_h_10(double *state, double *unused, double *out_374102871883193337);
void pose_H_10(double *state, double *unused, double *out_7438576236994118175);
void pose_h_13(double *state, double *unused, double *out_8419386726014748872);
void pose_H_13(double *state, double *unused, double *out_4076141149770791221);
void pose_h_14(double *state, double *unused, double *out_1661055795387027664);
void pose_H_14(double *state, double *unused, double *out_4827108180777942949);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}