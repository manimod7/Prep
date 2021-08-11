import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.text.*;

class Interval
{
  int start, end;
  Date date;
  Interval(int start, int end, Date date)
  {
    this.start = start;
    this.end = end;
    this.date = date;
  }
}

class TestClass
{
public
  static void main(String args[]) throws Exception
  {

    Scanner s = new Scanner(System.in);
    int n = s.nextInt();

    SimpleDateFormat ft = new SimpleDateFormat("yyyy-MM-dd");

    Set<String> user = new HashSet<String>();
    HashMap<Interval, ArrayList<String>> map = new HashMap<Interval, ArrayList<String>>();
    for (int i = 0; i < n; i++)
    {
      String opr = s.nextLine();

      if ((opr.substring(0, 3)).equals("add"))
      {
        String temp = opr.substring(9, opr.length());
        if (user.contains(temp))
        {
          System.out.println("failure");
        }
        else
        {
          user.add(temp);
          System.out.println("success")
        }
      }
      else if ((opr.substring(0, 6)).equals("create"))
      {
        int x = Integer.parseint(opr.substring(24, 27));
        int y = x + Integer.parseint(opr.substring(28, 30));
        String date = opr.substring(13, 23);
        Date t = ft.parse(date);
        String userList = opr.substring(31, opr.length());
        String[] list = userList.split(" ");
        if (x > 1440 || y > 1440)
        {
          System.out.println("failure";)
        }
        else
        {
          Interval temp = new Interval(x, y, t);
          map.put(temp, Arrays.asList(list));
          System.out.println("success");
        }
      }
      else if ((opr.substring(0, 4)).equals("show"))
      {
        String date = opr.substring(12, 22);
        Date t = ft.parse(date);
        String user = opr.substring(22, opr.length());
        Iterator it = map.entrySet().iterator();
        boolean check = false;
        while (it.hasNext())
        {
          Map.Entry element = (Map.Entry)it.next();
          Interval temp = element.getKey();
          if ((temp.date).compareTo(t) == 0)
          {
            ArrayList<String> str = element.getValue();
            if (str.contains(user))
            {
              System.out.print(temp.start + "-" + temp.end + " ");
              str.forEach(user->{ System.out.print(name + " "); });
              check = true;
            }
            System.out.println();
          }
        }
        if (!check)
        {
          System.out.println("none");
        }
      }
      else if ((opr.substring(0, 7)).equals("suggest"))
      {
        String date = opr.substring(13, 23);
        Date t = ft.parse(date);

        int x = Integer.parseint(opr.substring(24, 27));
        int y = Integer.parseint(opr.substring(28, 31));
        int dur = Integer.parseint(opr.substring(31, 33));

        String userList = opr.substring(33, opr.length());
        String[] list = userList.split(" ");

        Iterator it = map.entrySet().iterator();
        boolean check = false;
        while (it.hasNext())
        {
          Map.Entry element = (Map.Entry)it.next();
          Interval temp = element.getKey();
          if ((temp.date).compareTo(t) == 0)
          {
            boolean tempCheck = false;
            ArrayList<String> str = element.getValue();
            for (int i = 0; i < list.length; i++)
            {
              if (!str.contains(list[i]))
              {
                tempCheck = true;
                break;
              }
            }
            if (!tempCheck)
            {
            }
          }
        }
      }
      else
      {
        System.out.println("failure");
      }
    }
  }
}