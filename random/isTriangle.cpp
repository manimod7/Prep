class Point{
  public:
  int X;
  int Y;
  double Point_calculateDistance(Point *p1, Point *p2){
    return (p1->X - p2->X) * (p1->X - p2->X) + ((p1->Y - p2->Y) * (p1->Y - p2->Y))
  }
}

int isTriangle(Point *P1, Point *P2, Point *P3){
  double s1 = P1->Point_calculateDistance(P2);
  double s2 =P2->Point_calculateDistance(P3);
  double s3 = P3->Point_calculateDistance(P1);
  if(s1<s2+s3 && s2<s1+s3 && s3<s1+s2)
    return 1;
  return 0;

}