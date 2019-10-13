#!/usr/bin/ruby

def Gregorian(y) 
  a = y % 19
  b = (y/100).floor
  c = y % 100
  d = (b/4).floor
  e = b % 4
  f = ((b+8)/25).floor
  g = ((b-f+1)/3).floor
  h = (19*a+b-d-g+15)%30
  i = (c/4).floor
  k = c % 4
  l = (32+2*e+2*i-h-k)%7
  m = ((a+11*h+22*l)/451).floor
  month = ((h+l-7*m+114)/31).floor.to_i
  day = (((h+l-7*m+114) % 31) + 1).to_i

  return month, day
end

def Julian(y)
  a = y % 4
  b = y % 7
  c = y % 19
  d = (19*c + 15) % 30
  e = (2*a + 4*b - d + 34) % 7
  f = d + e + 114
  f, g = f/31, f%31

  return f, g+1
end

for i in 1000..2050
  m, d = Gregorian(i)
  mj, dj = Julian(i)
  puts "Gregorian: " + i.to_s + " " + m.to_s + " " + d.to_s + "\tJulian: " +  i.to_s + " " + mj.to_s + " " + dj.to_s
end
