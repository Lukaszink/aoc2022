#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int build(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);

int build(int time, int bot, int ore_ore, int cl_ore, int obs_ore,
          int obs_cl, int geo_ore, int geo_obs, int ore, int cl, int obs,
          int geo, int ore_r, int cl_r, int obs_r, int geo_r)
{

    // printf("Bots %d %d %d %d\n", ore_r, cl_r, obs_r, geo_r);
    while (((bot == 0 && ore < ore_ore) || (bot == 1 && ore < cl_ore) || (bot == 2 && (ore < obs_ore || cl < obs_cl)) || (bot == 3 && (obs < geo_obs || ore < geo_ore))) && time < 31)
    {
        time++;
        ore += ore_r;
        cl += cl_r;
        obs += obs_r;
        geo += geo_r;
    }

    if (time == 31)
    {
        return (geo + 2 * geo_r + (obs >= geo_obs && ore >= geo_ore));
    }

    if (cl_r > obs_cl)
        return 0;
    if (obs_r > geo_obs)
        return 0;
    if (ore_r > ore_ore && ore_r > cl_ore && ore_r > obs_ore && ore_r > geo_ore)
        return 0;

    ore += ore_r;
    cl += cl_r;
    obs += obs_r;
    geo += geo_r;

    if (bot == 0)
    {
        ore -= ore_ore;
        ore_r++;
    }

    if (bot == 1)
    {
        ore -= cl_ore;
        cl_r++;
    }

    if (bot == 2)
    {
        ore -= obs_ore;
        cl -= obs_cl;
        obs_r++;
    }
    if (bot == 3)
    {
        ore -= geo_ore;
        obs -= geo_obs;
        geo_r++;
    }

    int maxore = build(time + 1, 0, ore_ore, cl_ore, obs_ore, obs_cl, geo_ore, geo_obs, ore, cl, obs, geo, ore_r, cl_r, obs_r, geo_r);
    int maxcl = build(time + 1, 1, ore_ore, cl_ore, obs_ore, obs_cl, geo_ore, geo_obs, ore, cl, obs, geo, ore_r, cl_r, obs_r, geo_r);
    int maxobs = build(time + 1, 2, ore_ore, cl_ore, obs_ore, obs_cl, geo_ore, geo_obs, ore, cl, obs, geo, ore_r, cl_r, obs_r, geo_r);
    int maxgeo = build(time + 1, 3, ore_ore, cl_ore, obs_ore, obs_cl, geo_ore, geo_obs, ore, cl, obs, geo, ore_r, cl_r, obs_r, geo_r);

    int max = maxore;
    max = max > maxcl ? max : maxcl;
    max = max > maxobs ? max : maxobs;
    max = max > maxgeo ? max : maxgeo;

    return max;
}

void v1(FILE *);
void v2(FILE *);

int main()
{
    FILE *fp = fopen("in19.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    v1(fp);
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

        int b = build(0, 0, orerobot_cost_ore, clayrobot_cost_ore, obsrobot_cost_ore, obsrobot_cost_clay, georobot_cost_ore, georobot_cost_obs,
                      orerobot_cost_ore, 0, 0, 0, 0, 0, 0, 0);
        printf("%d\n", b);
        sum += iter * b;
    }
    printf("Sum: %d\n", sum);
}
