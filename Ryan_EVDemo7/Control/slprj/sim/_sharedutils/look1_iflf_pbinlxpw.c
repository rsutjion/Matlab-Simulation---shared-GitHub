#include "rtwtypes.h"
#include "rtw_shared_utils.h"

real32_T look1_iflf_pbinlxpw(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T prevIndex[], uint32_T maxIndex)
{
  real32_T frac;
  uint32_T startIndex;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T found;
  if (u0 <= bp0[0U]) {
    startIndex = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    startIndex = prevIndex[0U];
    iLeft = 0U;
    iRght = maxIndex;
    found = 0U;
    while (found == 0U) {
      if (u0 < bp0[startIndex]) {
        iRght = startIndex - 1U;
        startIndex = (iRght + iLeft) >> 1U;
      } else if (u0 < bp0[startIndex + 1U]) {
        found = 1U;
      } else {
        iLeft = startIndex + 1U;
        startIndex = (iRght + iLeft) >> 1U;
      }
    }

    frac = (u0 - bp0[startIndex]) / (bp0[startIndex + 1U] - bp0[startIndex]);
  } else {
    startIndex = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  prevIndex[0U] = startIndex;
  return (table[startIndex + 1U] - table[startIndex]) * frac + table[startIndex];
}
