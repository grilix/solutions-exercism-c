#include "space_age.h"

extern float convert_planet_age(float year_days, long seconds)
{
  return seconds / (((60 * 60) * 24) * year_days);
}
