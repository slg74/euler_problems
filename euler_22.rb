#!/usr/bin/ruby

require 'csv'
names = CSV.read('names.txt').first.sort

name_score = names.each.with_index(0).reduce(0) do |sum, (name, index)|
  sum + ((index + 1) * name.each_char.map { |e| e.ord - 64 }.reduce(:+))
end

puts name_score
