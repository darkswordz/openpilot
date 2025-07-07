#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_1249208308935262671);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7760717880286684729);
void pose_H_mod_fun(double *state, double *out_114789788435639618);
void pose_f_fun(double *state, double dt, double *out_3550080477287595771);
void pose_F_fun(double *state, double dt, double *out_9179238613370202642);
void pose_h_4(double *state, double *unused, double *out_3974230882824720906);
void pose_H_4(double *state, double *unused, double *out_3122410822710806054);
void pose_h_10(double *state, double *unused, double *out_1332363883864616286);
void pose_H_10(double *state, double *unused, double *out_4657406456673431633);
void pose_h_13(double *state, double *unused, double *out_8605248053788070713);
void pose_H_13(double *state, double *unused, double *out_6334684648043138855);
void pose_h_14(double *state, double *unused, double *out_5600738675960527785);
void pose_H_14(double *state, double *unused, double *out_7085651679050290583);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}