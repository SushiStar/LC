/*
 * We have two special characters. The first character can be
 * represented by one bit 0. The second chaeracter can be represented
 * by two bits (10 or 11).
 *
 * Now given a string represented by sevearl bits. Return whether the
 * last character must be a one-bit character or not. The given string
 * will always end with a zero.
 *
 * Date: 04/23/20020
 * Author: Wei Du
 */
class Solution {
public:
  bool isOneBitCharacter(vector<int> &bits) {
    if (bits.size() == 1)
      return true;
    int i = 0;
    for (; i < bits.size() - 1; ++i) {
      if (bits[i] == 0)
        continue;
      else
        ++i;
    }
    return (i == bits.size() - 1);
  }
};
