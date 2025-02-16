#ifndef BUILDING_BUILDING_H
#define BUILDING_BUILDING_H

#include "building/type.h"
#include "core/buffer.h"

//#define MAX_BUILDINGS[GAME_ENV] 10000
static const int MAX_BUILDINGS[2] = {
        2000,
        4000
};

typedef struct {
    int id;

    unsigned char state;
    unsigned char faction_id;
    unsigned char unknown_value;
    unsigned char size;
    unsigned char house_is_merged;
    unsigned char house_size;
    unsigned char x;
    unsigned char y;
    unsigned short grid_offset;
    short type;
    union {
        short house_level;
        short warehouse_resource_id;
        short workshop_type;
        short orientation;
        short fort_figure_type;
        short native_meeting_center_id;
        short market_goods;
        short roadblock_exceptions;
        short barracks_priority;
    } subtype;
    unsigned char road_network_id;
    unsigned short creation_sequence_index;
    short houses_covered;
    short percentage_houses_covered;
    short house_population;
    short house_population_room;
    short distance_from_entry;
    short house_highest_population;
    short house_unreachable_ticks;
    unsigned char road_access_x;
    unsigned char road_access_y;
    short figure_id;
    short figure_id2; // labor seeker or market buyer
    short immigrant_figure_id;
    short figure_id4; // tower ballista or burning ruin prefect
    unsigned char figure_spawn_delay;
    unsigned char figure_roam_direction;
    unsigned char has_water_access;
    int prev_part_building_id;
    int next_part_building_id;
    short loads_stored;
    unsigned char has_well_access;
    short num_workers;
    unsigned char labor_category;
    unsigned char output_resource_id;
    unsigned char has_road_access;
    unsigned char house_criminal_active;
    short damage_risk;
    short fire_risk;
    short fire_duration;
    unsigned char fire_proof; // cannot catch fire or collapse
    unsigned char house_figure_generation_delay;
    unsigned char house_tax_coverage;
    short formation_id;
    union {
        struct {
            short queued_docker_id;
            unsigned char num_ships;
            signed char orientation;
            short docker_ids[3];
            short trade_ship_id;
        } dock;
        struct {
            short inventory[8];
            short pottery_demand;
            short furniture_demand;
            short oil_demand;
            short wine_demand;
            unsigned char fetch_inventory_id;
        } market;
        struct {
            short resource_stored[16];
        } granary;
        struct {
            int unk_2[2];
            short progress;
            int unk_b[12];
            unsigned char has_fish;
            int unk_c[14];
            unsigned char blessing_days_left;
            unsigned char orientation;
            unsigned char has_raw_materials;
            int unk_1;
            unsigned char curse_days_left;
            int unk_6[6];
            short fishing_boat_id;
            int unk_40[40];
            unsigned char labor_state; // 0 = no laborers; 1 = present; 2 = just entered;
            unsigned char labor_days_left;
            int unk_12[12];
            unsigned char worker_id;
        } industry;
//        struct {
//            unsigned short progress;
//            unsigned char labor_state; // 0 = no laborers; 1 = present; 2 = just entered;
//            unsigned char labor_days_left;
//        } farm;
        struct {
            unsigned char num_shows;
            unsigned char days1;
            unsigned char days2;
//            unsigned char days3;
            unsigned char days3_or_play;
            unsigned short booth_corner_grid_offset;
            unsigned short ph_unk00_u32;
            unsigned short ph_unk01_u8;
            unsigned short ph_unk02_u8;
        } entertainment;
        struct {
            short foods_ph[8];
            short inventory[8];
            unsigned char theater;
            unsigned char amphitheater_actor;
            unsigned char amphitheater_gladiator;
            unsigned char colosseum_gladiator;
            unsigned char magistrate; // colosseum_lion
            unsigned char hippodrome;
            unsigned char school;
            unsigned char library;
            unsigned char academy;
            unsigned char barber;
            unsigned char clinic;
            unsigned char bathhouse;
            unsigned char hospital;
            unsigned char temple_ceres;
            unsigned char temple_neptune;
            unsigned char temple_mercury;
            unsigned char temple_mars;
            unsigned char temple_venus;
            unsigned char no_space_to_expand;
            unsigned char num_foods;
            unsigned char entertainment;
            unsigned char education;
            unsigned char health;
            unsigned char num_gods;
            unsigned char devolve_delay;
            unsigned char evolve_text_id;
        } house;
    } data;
    int tax_income_or_storage;
    unsigned char house_days_without_food;
    unsigned char ruin_has_plague;
    signed char desirability;
    unsigned char is_deleted;
    unsigned char is_adjacent_to_water;
    unsigned char storage_id;
    union {
        signed char house_happiness;
        signed char native_anger;
    } sentiment;
    unsigned char show_on_problem_overlay;
} building;

int building_find(int type);
building *building_get(int id);
building *building_main(building *b);
building *building_next(building *b);
building *building_top_xy(building *b);
building *building_create(int type, int x, int y);

void building_clear_related_data(building *b);
void building_clear_all(void);
//void building_totals_add_corrupted_house(int unfixable);

int building_is_house(int type);
int building_is_fort(int type);
int building_is_defense_ph(int type);
int building_is_farm(int type);
int building_is_floodplain_farm(building *b);
int building_is_workshop(int type);
int building_is_extractor(int type);
int building_is_monument(int type);
int building_is_senate(int type);
int building_is_temple(int type);
int building_is_large_temple(int type);
int building_is_shrine(int type);
int building_is_guild(int type);
int building_is_beautification(int type);
int building_is_water_crossing(int type);

int building_get_highest_id(void);
void building_update_highest_id(void);
void building_update_state(void);
void building_update_desirability(void);

int building_mothball_toggle(building *b);
int building_mothball_set(building *b, int value);

void building_save_state(buffer *buf, buffer *highest_id, buffer *highest_id_ever);
void building_load_state(buffer *buf, buffer *highest_id, buffer *highest_id_ever);

#endif // BUILDING_BUILDING_H
