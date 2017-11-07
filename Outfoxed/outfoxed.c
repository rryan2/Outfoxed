#include "outfoxed.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdint.h>

//initialize global variables
int clueColors[NUMBER_OF_CLUES]; //integer 1 represents red and 0 represents green
sem_t hat_sem;
sem_t umbrella_sem;
sem_t glasses_sem;
sem_t monocle_sem;
sem_t flower_sem;
sem_t coat_sem;
sem_t cane_sem;
sem_t gloves_sem;
sem_t watch_sem;
sem_t necklace_sem;
sem_t briefcase_sem;
sem_t scarf_sem;
sem_t process_sem;
sem_t detective_sem;
pthread_muxtex_t chicken_mutex;
bool matched_clue;
bool can_be_eliminate;
bool game_over;
int size_of_current_suspects;
int theif_id;

/* To give you a chance to (re-)initialize any data structures you may need,
 * we will call setup_play() every time a new game starts.
 * Thus, setup_play() may be called multiple times during one program run.
 */
extern void setup_play(void)
{
  sem_init(&hat_sem, 0, 0);
  sem_init(&umbrella_sem, 0, 0);
  sem_init(&glasses_sem, 0, 0);
  sem_init(&monocle_sem, 0, 0);
  sem_init(&flower_sem, 0, 0);
  sem_init(&coat_sem, 0, 0);
  sem_init(&cane_sem, 0, 0);
  sem_init(&gloves_sem, 0, 0);
  sem_init(&watch_sem, 0, 0);
  sem_init(&necklace_sem, 0, 0);
  sem_init(&briefcase_sem, 0, 0);
  sem_init(&scarf_sem, 0, 0);
  sem_init(&process_sem, 0, 0);
  sem_init(&detective_sem, 0, 0);
  game_over = false;
  size_of_current_suspects = 0;
  pthread_muxtex_init(&chicken_mutex, NULL);
  int i;
  for (i = 0; i < NUMBER_OF_CLUES; i++)
  {
    clueColors[i] = 0;
  }

}
/* Each detective thread will execute the chicken_detective_thread
 * function.  A detective thread must return
 * when the suspect has been found.
 */
extern void * chicken_detective_thread(void * args)
{
  pthread_muxtex_lock(chicken_mutex);
  if (game_over == false)
  {
    while(1)
    {
      sem_wait(&detective_sem);
      int i;
      for (i = 0; i < NUMBER_OF_SUSPECTS; i++)
      {
        check_for_eliminate(i);
        if (theif_id != -1)
        {
          announce_thief(&suspects[i]);
          game_over = true;
          pthread_muxtex_unlock(&chicken_mutex);
          return NULL:
        }
      }

    }
  }
  else{
    pthread_muxtex_unlock(&chicken_mutex);
    return NULL;
  }
  return NULL;
}

extern void check_for_eliminate(int i)
{
  int matched_size;
  matched_size = 0;
  theif_id = -1;
  int j;
  for (j = 0; j < 3; j++)
  {
    check_for_clues(suspects[i].clues[j]);
    if (can_be_eliminate == true)
    {
      eliminate_suspect(&suspects[i]);
      size_of_current_suspects--;
      break;
    }
    if (matched_clue == true)
    {
      matched_size++;
    }
  }
  if (matched_size == 3)
  {
    theif_id = i;
  }

}

extern void check_for_clues(enum Clue clue)
{
  matched_clue = false;
  can_be_eliminate = false;
  if (clue == hat)
  {
    if(clueColors[0] == 1)
    {
      matched_clue = true;
    }
    else
    {
      can_be_eliminate = true;
    }
    break;
  }

  else if (clue == umbrella)
  {
    if (clue == umbrella)
    {
      if(clueColors[1] == 1)
      {
        matched_clue = true;
      }
      else
      {
        can_be_eliminate = true;
      }
      break;
  }
}

  else if (clue == glasses)
  {
    if (clue == glasses)
    {
      if(clueColors[2] == 1)
      {
        matched_clue = true;
      }
      else
      {
        can_be_eliminate = true;
      }
      break;
    }
  }

  else if (clue == monocle)
  {
    if (clue == monocle)
    {
      if(clueColors[3] == 1)
      {
        matched_clue = true;
      }
      else{
        can_be_eliminate = true;
      }
      break;
    }
  }

  else if (clue == flower)
  {
    if (clue == flower)
    {
      if(clueColors[4] == 1)
      {
        matched_clue = true;
      }
      else{
        can_be_eliminate = true;
      }
      break;
    }
  }

  else if (clue == coat)
  {
    if (clue == coat)
    {
      if(clueColors[5] == 1)
      {
        matched_clue = true;
      }
      else{
        can_be_eliminate = true;
      }
      break;
    }
  }

  else if (clue == cane)
  {
    if (clue == cane)
    {
      if(clueColors[6] == 1)
      {
        matched_clue = true;
      }
      else{
        can_be_eliminate = true;
      }
      break;
    }
  }

  else if (clue == gloves)
  {
    if (clue == gloves)
    {
      if(clueColors[7] == 1)
      {
        matched_clue = true;
      }
      else{
        can_be_eliminate = true;
      }
      break;
    }
  }

  else if (clue == watch)
  {
    if (clue == watch)
    {
      if(clueColors[8] == 1)
      {
        matched_clue = true;
      }
      else{
        can_be_eliminate = true;
      }
      break;
    }
  }

  else if (clue == necklace)
  {
    if (clue == necklace)
    {
      if(clueColors[9] == 1)
      {
        matched_clue = true;
      }
      else{
        can_be_eliminate = true;
      }
      break;
    }
  }

  else if (clue == briefcase)
  {
    if (clue == briefcase)
    {
      if(clueColors[10] == 1)
      {
        matched_clue = true;
      }
      else{
        can_be_eliminate = true;
      }
      break;
    }
  }

  else if (clue == scarf)
  {
    if (clue == scarf)
    {
      if(clueColors[11] == 1)
      {
        matched_clue = true;
      }
      else{
        can_be_eliminate = true;
      }
      break;
    }
  }
  // int i;
  // for (i = 0; i < NUMBER_OF_CLUES; i++)
  // {
  //
  // }
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
  sem_wait(&process_sem);
  size_of_current_suspects++;
  if (size_of_current_suspects > NUMBER_OF_SUSPECTS)
  {
    semi_post(&detective_sem);
  }
  else
  {
    sem_post(&process_sem);
  }
  return NULL;


}

/* (3) Clues. Each clue shows up in a separate thread.
 * You must implement the 12 functions below such that
 *
 * (a) Each clue is decoded by the clue thread responsible for it.
 * (b) The clues are decoded in exactly the order prescribed by your
 *     personal code, which is listed on the website.
 *
 * Clue (thread)s must also return before the game can end.
 * necklace umbrella monocle flower briefcase watch glasses cane coat hat gloves scarf
 */
extern void * hat_thread(void * args)
{
  sem_wait(&coat_sem);
  if (decode_clue(hat) == RED) //check if the clue belongs to the thief
  {
    clueColors[0] = 1;
  }
  else
  {
    clueColors[0] = 0;
  }
  semi_post(&hat_sem);
  return NULL;
}

extern void * umbrella_thread(void * args)
{
  sem_wait(&necklace_sem);
  if (decode_clue(umbrella) == RED) //check if the clue belongs to the thief
  {
    clueColors[1] = 1;
  }
  else
  {
    clueColors[1] = 0;
  }
  semi_post(&umbrella_sem);
  return NULL;
}

extern void * glasses_thread(void * args)
{
  sem_wait(&watch_sem);
  if (decode_clue(glasses) == RED) //check if the clue belongs to the thief
  {
    clueColors[2] = 1;
  }
  else
  {
    clueColors[2] = 0;
  }
  semi_post(&glasses_sem);
  return NULL;
}

extern void * monocle_thread(void * args)
{
  sem_wait(&umbrella_sem);
  if (decode_clue(monocle) == RED) //check if the clue belongs to the thief
  {
    clueColors[3] = 1;
  }
  else
  {
    clueColors[3] = 0;
  }
  semi_post(&monocle_sem);
  return NULL;
}

extern void * flower_thread(void * args)
{
  sem_wait(&monocle_sem);
  if (decode_clue(flower) == RED) //check if the clue belongs to the thief
  {
    clueColors[4] = 1;
  }
  else
  {
    clueColors[4] = 0;
  }
  semi_post(&flower_sem);
  return NULL;
}

extern void * coat_thread(void * args)
{
  sem_wait(&cane_sem);
  if (decode_clue(coat) == RED) //check if the clue belongs to the thief
  {
    clueColors[5] = 1;
  }
  else
  {
    clueColors[5] = 0;
  }
  semi_post(&coat_sem);
  return NULL;
}

extern void * cane_thread(void * args)
{
  sem_wait(&glasses_sem);
  if (decode_clue(cane) == RED) //check if the clue belongs to the thief
  {
    clueColors[6] = 1;
  }
  else
  {
    clueColors[6] = 0;
  }
  semi_post(&cane_sem);
  return NULL;
}

extern void * gloves_thread(void * args)
{
  sem_wait(&hat_sem);
  if (decode_clue(gloves) == RED) //check if the clue belongs to the thief
  {
    clueColors[7] = 1;
  }
  else
  {
    clueColors[7] = 0;
  }
  semi_post(&gloves_sem);
  return NULL;
}

extern void * watch_thread(void * args)
{
  sem_wait(&briefcase_sem);
  if (decode_clue(watch) == RED) //check if the clue belongs to the thief
  {
    clueColors[8] = 1;
  }
  else
  {
    clueColors[8] = 0;
  }
  semi_post(&watch_sem);
  return NULL;
}

extern void * necklace_thread(void * args)
{
  if (decode_clue(necklace) == RED) //check if the clue belongs to the thief
  {
    clueColors[9] = 1;
  }
  else
  {
    clueColors[9] = 0;
  }
  sem_post(&necklace_sem);
  return NULL;
}

extern void * briefcase_thread(void * args)
{
  sem_wait(&flower_sem);
  if (decode_clue(briefcase) == RED) //check if the clue belongs to the thief
  {
    clueColors[10] = 1;
  }
  else
  {
    clueColors[10] = 0;
  }
  sem_post(&briefcase);
  return NULL;
}

extern void * scarf_thread(void * args)
{
  sem_wait(&gloves_sem);
  if (decode_clue(hat) == RED) //check if the clue belongs to the thief
  {
    clueColors[11] = 1;
  }
  else
  {
    clueColors[11] = 0;
  }
  sem_post(&process_sem);
  return NULL;
}
