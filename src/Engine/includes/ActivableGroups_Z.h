#ifndef _ACTIVABLEGROUPS_Z_H_
#define _ACTIVABLEGROUPS_Z_H_

enum ActivableGroup_Z {
    ag_notpaused_first = 0,
    ag_notpaused_second = 1,
    ag_notpaused_third = 2,
    ag_notpaused_last = 3,
    ag_bones = 4,
    ag_play_animation = 5,
    ag_move_first = 6,
    ag_move_second = 7,
    ag_move_third = 8,
    ag_move_last = 9,
    ag_game_manager = 10,
    ag_collision = 11,
    ag_camera = 12,
    ag_camera_occlusion = 13,
    ag_camera_stream = 14,
    ag_clipping = 15,
    ag_particles = 16,
    ag_dynamic_anim = 17,
    ag_no_group = 18,
    ag_draw = 19,
    ag_draw_notpaused = 20,
    ag_unk_0x15 = 21,
    ag_ui_draw_notpaused = 22,
    ag_ui_draw = 23,
    ag_loading_draw_notpaused = 24,
    ag_unk_0x19 = 25,
    ag_movie_draw_notpaused = 26,
    ag_last_notpaused = 27,
};

#endif
