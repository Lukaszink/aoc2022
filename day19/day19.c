#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int blueprint(int time, int ore_robot_cost, int clay_robot_cost, int obs_robot_ore,
              int obs_robot_clay, int geode_robot_ore, int geode_robot_obs, int ore, int clay, int obsidian,
              int geodes, int ore_robots, int clay_robots, int obsidian_robots, int geode_robots)
{
    if (time == 24)
    {
        // printf("%d", geodes);
        return geodes;
    }
    int new_ore = ore + ore_robots;
    int new_clay = clay + clay_robots;
    int new_obsidian = obsidian + obsidian_robots;
    int new_geodes = geodes + geode_robots;

    int canbore = ore >= ore_robot_cost;
    int canbclay= ore >= clay_robot_cost;
    int canbobs = ore >= obs_robot_ore && clay >= obs_robot_clay;
    int canbgeo = ore >= geode_robot_ore && obsidian >= geode_robot_obs;

    int canball = canbore && canbclay && canbobs && canbgeo;
    int build_nothing = (!canball) ? blueprint(time + 1, ore_robot_cost, clay_robot_cost, obs_robot_ore,
                                  obs_robot_clay, geode_robot_ore, geode_robot_obs, new_ore, new_clay, new_obsidian, new_geodes,
                                  ore_robots, clay_robots, obsidian_robots, geode_robots) : 0;

    int build_ore_robot = ore >= ore_robot_cost ? blueprint(time + 1, ore_robot_cost, clay_robot_cost, obs_robot_ore,
                                                            obs_robot_clay, geode_robot_ore, geode_robot_obs, new_ore - ore_robot_cost, new_clay, new_obsidian, new_geodes,
                                                            ore_robots + 1, clay_robots, obsidian_robots, geode_robots)
                                                : 0;

    int build_clay_robot = ore >= clay_robot_cost ? blueprint(time + 1, ore_robot_cost, clay_robot_cost, obs_robot_ore,
                                                              obs_robot_clay, geode_robot_ore, geode_robot_obs, new_ore - clay_robot_cost, new_clay, new_obsidian, new_geodes,
                                                              ore_robots, clay_robots + 1, obsidian_robots, geode_robots)
                                                  : 0;

    int build_obs_robot = ore >= obs_robot_ore && clay >= obs_robot_clay ? blueprint(time + 1, ore_robot_cost, clay_robot_cost, obs_robot_ore,
                                                                                     obs_robot_clay, geode_robot_ore, geode_robot_obs, new_ore - obs_robot_ore, new_clay - obs_robot_clay, new_obsidian, new_geodes,
                                                                                     ore_robots, clay_robots, obsidian_robots + 1, geode_robots)
                                                                         : 0;

    int build_geode_robot = ore >= geode_robot_ore && obsidian >= geode_robot_obs ? blueprint(time + 1, ore_robot_cost, clay_robot_cost, obs_robot_ore,
                                                                                              obs_robot_clay, geode_robot_ore, geode_robot_obs, new_ore - geode_robot_ore, new_clay, new_obsidian - geode_robot_obs, new_geodes,
                                                                                              ore_robots, clay_robots, obsidian_robots, geode_robots + 1)
                                                                                  : 0;

    // oder nur geodes?
    int max1 = build_ore_robot > geodes ? build_ore_robot : geodes;
    int max2 = build_clay_robot > max1 ? build_clay_robot : max1;
    int max3 = build_obs_robot > max2 ? build_obs_robot : max2;
    int max4 = build_geode_robot > max3 ? build_geode_robot : max3;
    int max5 = build_nothing > max4 ? build_nothing : max4;
    return max5;
}

void v1(FILE *);
void v2(FILE *);

int main()
{
    FILE *fp = fopen("in19.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    v2(fp);
    // v2(fp);
}

void v1(FILE *f)
{
    int iter;
    int orerobot_cost_ore;
    int clayrobot_cost_ore;
    int obsrobot_cost_clay;
    int obsrobot_cost_ore;
    int georobot_cost_ore;
    int georobot_cost_obs;

    int sum = 0;
    while (fscanf(f, "Blueprint %d: Each ore robot costs %d ore. ", &iter, &orerobot_cost_ore) > 0)
    {
        fscanf(f, "Each clay robot costs %d ore. ", &clayrobot_cost_ore);
        fscanf(f, "Each obsidian robot costs %d ore and %d clay. ", &obsrobot_cost_ore, &obsrobot_cost_clay);
        fscanf(f, "Each geode robot costs %d ore and %d obsidian.\n", &georobot_cost_ore, &georobot_cost_obs);

        printf("BP %d: %d %d %d,%d %d,%d\n", iter, orerobot_cost_ore, clayrobot_cost_ore, obsrobot_cost_ore, obsrobot_cost_clay, georobot_cost_ore, georobot_cost_obs);

        int b = blueprint(0, orerobot_cost_ore, clayrobot_cost_ore, obsrobot_cost_ore, obsrobot_cost_clay, georobot_cost_ore, georobot_cost_obs,
                          0, 0, 0, 0, 1, 0, 0, 0);
        printf("%d\n", b);
        sum += iter * b;
    }
    printf("Sum: %d\n", sum);
}

void v2(FILE *f)
{
    int iter;
    int orerobot_cost_ore;
    int clayrobot_cost_ore;
    int obsrobot_cost_clay;
    int obsrobot_cost_ore;
    int georobot_cost_ore;
    int georobot_cost_obs;



    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        fscanf(f, "Blueprint %d: Each ore robot costs %d ore. ", &iter, &orerobot_cost_ore);
        fscanf(f, "Each clay robot costs %d ore. ", &clayrobot_cost_ore);
        fscanf(f, "Each obsidian robot costs %d ore and %d clay. ", &obsrobot_cost_ore, &obsrobot_cost_clay);
        fscanf(f, "Each geode robot costs %d ore and %d obsidian.\n", &georobot_cost_ore, &georobot_cost_obs);

        printf("BP %d: %d %d %d,%d %d,%d\n", iter, orerobot_cost_ore, clayrobot_cost_ore, obsrobot_cost_ore, obsrobot_cost_clay, georobot_cost_ore, georobot_cost_obs);

        int b = blueprint(0, orerobot_cost_ore, clayrobot_cost_ore, obsrobot_cost_ore, obsrobot_cost_clay, georobot_cost_ore, georobot_cost_obs,
                          0, 0, 0, 0, 1, 0, 0, 0);
        printf("%d\n", b);
        sum *= b;
    }
    printf("Sum: %d\n", sum);
}