#include "outfoxed.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct detective_strcuct {
  Suspect suspect;
};

static int main(int argc, char const *argv[]) {

  /* code */

//create chiken detectives threads
create_detective_threads();


  return 0;
}
/*
 * create the multi-threads for four chicked threads
 */
extern void create_detective_threads()
{
  pthread_t tids[NUMBER_OF_DETECTIVES];
  struct detective_strcuct args[NUMBER_OF_DETECTIVES];
  int i;
  for (i = 0; i < NUMBER_OF_DETECTIVES; i++)
  {
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tids[i], &attr, chicken_detective_thread, &args[i]);
  }

  //wait for threads are done
  int j;
  for (j = 0; j < NUMBER_OF_DETECTIVES; j++)
  {
    pthread_join(tids[j], NULL);
    if (args[j] != NULL) //reveals the suspect
    {
      announce_thief(args[j]->suspect);
      //print the suspect and set up a new game--optional
    }
  }
}

/* Each detective thread will execute the chicken_detective_thread
 * function.  A detective thread must return
 * when the suspect has been found.
 */
extern void * chicken_detective_thread(void *)
{
  //eliminate_suspect
  //assign the suspect if null or not
  pthread_exit(0);
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
extern void * hat_thread(void * arg)
{
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_t tid;
  pthread_create(&tid, &attr, decoded_clue, &arg);

}
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
