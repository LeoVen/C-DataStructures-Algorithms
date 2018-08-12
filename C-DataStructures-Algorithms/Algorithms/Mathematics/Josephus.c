/**
 * @file Josephus.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 22/04/2018
 *
 * @brief Josephus problem solving
 *
 */

#include "Mathematics.h"

/**
 * People are standing in a circle waiting to be executed. Counting begins at a
 * specified point in the circle and proceeds around the circle in a specified
 * direction. After a specified number of people are skipped, the next person
 * is executed. The procedure is repeated with the remaining people, starting
 * with the next person, going in the same direction and skipping the same
 * number of people, until only one person remains, and is freed.
 *
 * The problem � given the number of people (n) and number to be skipped (k),
 * is to choose the position in the initial circle to avoid execution.
 *
 * @param[in] n Number of people
 * @param[in] k Skip value
 *
 * @return int Position to be at to avoid being executed
 *
 */
size_t Josephus(size_t n, size_t k)
{

  if (n == 1)
    return 1;

  return ((Josephus(n - 1, k) + k - 1) % n) + 1;
}