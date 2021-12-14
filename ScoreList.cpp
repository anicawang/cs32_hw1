//
//  ScoreList.cpp
//  Project 2
//
//  Created by Anica Wang on 1/14/21.
//

#include "ScoreList.h"
#include "Sequence.h"

ScoreList::ScoreList()       // Create an empty score list.
{
    items = 0;
}

bool ScoreList::add(unsigned long score)
  // If the score is valid (a value from 0 to 100) and the score list
  // has room for it, add it to the score list and return true.
  // Otherwise, leave the score list unchanged and return false.
{
    if (score >= 0 && score <= 100 && items < DEFAULT_MAX_ITEMS)
    {
        m_items.insert(score);
        items++;
        return true;
    }
    return false;
}

bool ScoreList::remove(unsigned long score)
  // Remove one instance of the specified score from the score list.
  // Return true if a score was removed; otherwise false.
{
    int pos = m_items.find(score);
    if (pos != -1)
    {
        m_items.erase(pos);
        items--;
        return true;
    }
    return false;
}

int ScoreList::size() const  // Return the number of scores in the list.
{
    return items;
}

unsigned long ScoreList::minimum() const
  // Return the lowest-valued score in the score list.  If the list is
  // empty, return NO_SCORE.
{
    if (items == 0)
    {
        return NO_SCORE;
    }
    
    unsigned long min;
    m_items.get(0, min);
    unsigned long temp;
    
    for (int i = 0; i < items; i++)
    {
        m_items.get(i, temp);
        if (temp < min)
        {
            min = temp;
        }
    }
    return min;
}

unsigned long ScoreList::maximum() const
{
    if (items == 0)
    {
        return NO_SCORE;
    }
    
    unsigned long max;
    m_items.get(0, max);
    unsigned long temp;
    
    for (int i = 0; i < items; i++)
    {
        m_items.get(i, temp);
        if (temp > max)
        {
            max = temp;
        }
    }
    return max;
}
