#include <outfoxed.h>
#include <stdlib.h>
#include <pthread>

static void int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}


/* Each detective thread will execute the chicken_detective_thread
 * function.  A detective thread must return
 * when the suspect has been found.
 */
extern void * chicken_detective_thread(void *)
{

}

/* Suspects.  Whenever a new suspect card is turned over, a new thread
 * will be created and starts executing the function 'new_suspect_thread,'
 * which you must implement.  The void * argument points to the suspect
 * that was revealed.  Suspects may appear in random order!
 *
 * Suspect (thread)s must return before the game can end.
 */
extern void * new_suspect_thread(void * suspect)
{

}

/* (3) Clues. Each clue shows up in a separate thread.
 * You must implement the 12 functions below such that
 *
 * (a) Each clue is decoded by the clue thread responsible for it.
 * (b) The clues are decoded in exactly the order prescribed by your
 *     personal code, which is listed on the website.
 *
 * Clue (thread)s must also return before the game can end.
 */
extern void * hat_thread(void *);
extern void * umbrella_thread(void *);
extern void * glasses_thread(void *);
extern void * monocle_thread(void *);
extern void * flower_thread(void *);
extern void * coat_thread(void *);
extern void * cane_thread(void *);
extern void * gloves_thread(void *);
extern void * watch_thread(void *);
extern void * necklace_thread(void *);
extern void * briefcase_thread(void *);
extern void * scarf_thread(void *);
