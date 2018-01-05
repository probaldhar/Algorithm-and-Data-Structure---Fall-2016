/**
 * Defines all data types and declares all function prototypes for measuring elapsed time.
 *
 * @author T. Reichherzer
 */

#ifndef _TIME_H
#define _TIME_H

/**
 * Starts the timer
 */
void startTimer ();

/**
 * Stops the timer and returns the elapsed time.
 * Requires that start_timer is called before this function is called.
 *
 * @return the elapsed time measured in seconds and fraction of nano seconds
 */
 float stopTimer();

#endif