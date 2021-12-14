//
//  Sequence.cpp
//  Project 2
//
//  Created by Anica Wang on 1/14/21.
//

#include "Sequence.h"
#include <iostream>

using namespace std;

Sequence::Sequence()    // Create an empty sequence (i.e., one with no items)
{
    nItems = 0;
}

bool Sequence::empty() const // Return true if the sequence is empty, otherwise false.
{
    if (nItems == 0)
    {
        return true;
    }
    return false;
}

int Sequence::size() const   // Return the number of items in the sequence.
{
    return nItems;
}

int Sequence::insert(int pos, const ItemType& value)
// Insert value into the sequence so that it becomes the item at
// position pos.  The original item at position pos and those that
// follow it end up at positions one higher than they were at before.
// Return pos if 0 <= pos <= size() and the value could be
// inserted.  (It might not be, if the sequence has a fixed capacity,
// e.g., because it's implemented using a fixed-size array.)  Otherwise,
// leave the sequence unchanged and return -1.  Notice that
// if pos is equal to size(), the value is inserted at the end.
{
    int i = 0;

    if (nItems > DEFAULT_MAX_ITEMS || pos >= DEFAULT_MAX_ITEMS)
    {
        return -1;
    }

    else if ((0 <= pos && pos <= size()) && (nItems < DEFAULT_MAX_ITEMS && pos < DEFAULT_MAX_ITEMS))
    {
        nItems++;
        for (i = nItems - 1; i > pos; i--)
        {
            seq[i] = seq[i - 1];
        }
        seq[pos] = value;
        return pos;
    }
    return -1;
}

int Sequence::insert(const ItemType& value)
  // Let p be the smallest integer such that value <= the item at
  // position p in the sequence; if no such item exists (i.e.,
  // value > all items in the sequence), let p be size().  Insert
  // value into the sequence so that it becomes the item in position
  // p.  The original item at position p and those that follow it end
  // up at positions one higher than before.  Return p if the value
  // was actually inserted.  Return -1 if the value was not inserted
  // (perhaps because the sequence has a fixed capacity and is full).
{
    //1 5 4 6 2 (3) goes before 5

    int p = 0;
    int i = 0;
    if (nItems >= DEFAULT_MAX_ITEMS)
    {
        return -1;
    }

    if (nItems < DEFAULT_MAX_ITEMS)
    {
        while (p < nItems && seq[p] < value)
        {
            p++;
        }

        nItems++;
        for (i = nItems - 1; i > p; i--)
        {
            seq[i] = seq[i - 1];
        }
        seq[p] = value;

    }
    return p;
}

bool Sequence::erase(int pos)
  // If 0 <= pos < size(), remove the item at position pos from
  // the sequence (so that all items that followed that item end up at
  // positions one lower than they were at before), and return true.
  // Otherwise, leave the sequence unchanged and return false.
{
    if (pos >= 0 && pos < size() && nItems > 0)
    {
        for (int i = pos; i < nItems - 1; i++)
        {
            seq[i] = seq[i + 1];
        }
        nItems--;
        return true;
    }
    return false;
}

int Sequence::remove(const ItemType& value)
  // Erase all items from the sequence that == value.  Return the
  // number of items removed (which will be 0 if no item == value).
{
    int num = 0;
    for (int i = 0; i < nItems; i++)
    {
        if (seq[i] == value)
        {
            erase(i);
            i--;
            num++;
        }
    }
    return num;
}

bool Sequence::get(int pos, ItemType& value) const
  // If 0 <= pos < size(), copy into value the item at position pos
  // of the sequence and return true.  Otherwise, leave value unchanged
  // and return false.
{
    if (pos >= 0 && pos < size())
    {
        value = seq[pos];
        return true;
    }
    return false;
}

bool Sequence::set(int pos, const ItemType& value)
  // If 0 <= pos < size(), replace the item at position pos in the
  // sequence with value and return true.  Otherwise, leave the sequence
  // unchanged and return false.
{
    if (pos >= 0 && pos < size())
    {
        seq[pos] = value;
        return true;
    }
    return false;
}

int Sequence::find(const ItemType& value) const
  // Let p be the smallest integer such that value == the item at
  // position p in the sequence; if no such item exists, let p be -1.
  // Return p.
{
    int p = -1;
    for (int i = 0; i < nItems; i++)
    {
        if (value == seq[i])
        {
            p = i;
        }
    }
    return p;


}

void Sequence::swap(Sequence& other)
  // Exchange the contents of this sequence with the other one.
  // FIX ME
{
    ItemType temp;
    int s;
    if (other.nItems <= nItems && nItems <= DEFAULT_MAX_ITEMS)
    {
        for (int i = 0; i < nItems; i++)
        {
            temp = other.seq[i];
            other.seq[i] = seq[i];
            seq[i] = temp;
        }

        s = other.nItems;
        other.nItems = nItems;
        nItems = s;
    }

    else if (other.nItems >= nItems && nItems <= DEFAULT_MAX_ITEMS)
    {
        for (int i = 0; i < other.nItems; i++)
        {
            temp = other.seq[i];
            other.seq[i] = seq[i];
            seq[i] = temp;
        }

        s = other.nItems;
        other.nItems = nItems;
        nItems = s;
    }

    else
    {
        for (int i = 0; i < other.nItems; i++)
        {
            temp = other.seq[i];
            other.seq[i] = seq[i];
            seq[i] = temp;
        }
    }
}

//void Sequence::dump()
//{
//    for (int i = 0; i < size(); i++)
//    {
//        cout << seq[i] << endl;
//    }
//}
