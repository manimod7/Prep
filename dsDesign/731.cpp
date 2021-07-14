class MyCalendarTwo
{
public:
  //  If booking at a given time stamp is 2 then false as no more booking can be done
  //      we maintain 2 vectors, one for single booking and one for double booking
  vector<pair<int, int>> singleB, doubleB;
  MyCalendarTwo()
  {
    singleB.clear();
    doubleB.clear();
  }

  bool book(int start, int end)
  {
    bool isDouble = false;

    // st->first fn->second
    for (auto [st, fn] : doubleB)
    {
      if (start < fn && end > st)
      {
        isDouble = true;
        break;
      }
    }

    if (isDouble)
      return false;

    for (auto [st, fn] : singleB)
    {
      // update the booking in double if any booking exists
      if (start < fn && end > st)
        doubleB.push_back({max(start, st), min(end, fn)});
      // the overlapping schedule is only updated in double
    }

    // single is also updated since [.(.]..) this kind of overlap could be there
    //     and if we dont update single list then we would miss extra part of the booking
    //          that is not covered in double booking
    singleB.push_back({start, end});
    return true;
  }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
