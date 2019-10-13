#!/usr/bin/perl
#
# Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
#
#
# For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
#
# What is the total of all the name scores in the file?
#

use strict;
use warnings;
use List::Util qw(sum); 

my @n = (); 
my $f = 'names.txt';
open my $fh, '<', $f or die 'cannot open: $!';
while (<$fh>) {
    my @fields = split(',', $_);
    for (@fields) {
        s/\"//; s/\"//; 
        push @n, $_; 
    }
}

my @sorted = sort { $a cmp $b } @n;
my @name_scores = (); 
my $posn = 1;
for (@sorted) {
    push @name_scores, ($posn * word_value($_)); 
    $posn++; 
}

#
# input - a string
# output - the sum of all letter values in the string, i.e. A=1, B=2, C=3.
#          an input of "CAB" would return 6. 
#
sub word_value {
    my $word = shift;
    my @wordarr = split('', $word); 
    my %h;
    @h{'A' .. 'Z'} = (1 .. 26);
    my $total = 0;
    for my $i (@wordarr) {
        $total += $h{$i};
    }
    return $total;
}

print sum(@name_scores); 

