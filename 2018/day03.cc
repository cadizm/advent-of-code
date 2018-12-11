#include <iostream>
#include <fstream>
#include <map>
#include <vector>

// --- Day 3: No Matter How You Slice It ---
// The Elves managed to locate the chimney-squeeze prototype fabric for
// Santa's suit (thanks to someone who helpfully wrote its box IDs on the wall
// of the warehouse in the middle of the night). Unfortunately, anomalies are
// still affecting them - nobody can even agree on how to cut the fabric.
//
// The whole piece of fabric they're working on is a very large square - at
// least 1000 inches on each side.
//
// Each Elf has made a claim about which area of fabric would be ideal for
// Santa's suit. All claims have an ID and consist of a single rectangle with
// edges parallel to the edges of the fabric. Each claim's rectangle is
// defined as follows:
//
// The number of inches between the left edge of the fabric and the left edge
// of the rectangle.
// The number of inches between the top edge of the fabric and the top edge of
// the rectangle.
// The width of the rectangle in inches.
// The height of the rectangle in inches.
// A claim like #123 @ 3,2: 5x4 means that claim ID 123 specifies a rectangle
// 3 inches from the left edge, 2 inches from the top edge, 5 inches wide, and
// 4 inches tall. Visually, it claims the square inches of fabric represented
// by # (and ignores the square inches of fabric represented by .) in the
// diagram below:
//
// ...........
// ...........
// ...#####...
// ...#####...
// ...#####...
// ...#####...
// ...........
// ...........
// ...........
// The problem is that many of the claims overlap, causing two or more claims
// to cover part of the same areas. For example, consider the following claims:
//
// #1 @ 1,3: 4x4
// #2 @ 3,1: 4x4
// #3 @ 5,5: 2x2
// Visually, these claim the following areas:
//
// ........
// ...2222.
// ...2222.
// .11XX22.
// .11XX22.
// .111133.
// .111133.
// ........
// The four square inches marked with X are claimed by both 1 and 2. (Claim 3,
// while adjacent to the others, does not overlap either of them.)
//
// If the Elves all proceed with their own plans, none of them will have
// enough fabric. How many square inches of fabric are within two or more
// claims?

// (1,3) (2,3) (3,3) (4,3)
// (1,4) (2,4) (3,4) (4,4)
// (1,5) (2,5) (3,5) (4,5)
// (1,6) (2,6) (3,6) (4,6)

int part1() {
  std::ifstream f("data/day03.input.part1");

  std::map<std::pair<int, int>, int> map;
  int left, top, width, height;

  while (f >> left >> top >> width >> height) {
    for (int i = 0; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
        auto key = std::make_pair(left + j, top + i);
        auto kv = map.find(key);
        if (kv != map.end()) {
          map[key] += 1;
        } else {
          map[key] = 1;
        }
      }
    }
  }

  int count = 0;
  for (auto kv : map) {
    if (kv.second > 1) {
      count++;
    }
  }

  return count;
}

// --- Part Two ---
// Amidst the chaos, you notice that exactly one claim doesn't overlap by even
// a single square inch of fabric with any other claim. If you can somehow
// draw attention to it, maybe the Elves will be able to make Santa's suit
// after all!
//
// For example, in the claims above, only claim 3 is intact after all claims
// are made.
//
// What is the ID of the only claim that doesn't overlap?

int part2() {
  std::ifstream f("data/day03.input.part2");

  // (left, top) -> overlap count
  std::map<std::pair<int, int>, int> pos_count;

  // claim -> list of (left, top)
  std::map<int, std::vector<std::pair<int, int>>> claim_positions;

  // read input and map:
  //   1. position to overlap count
  //   2. claim to list of positions
  int claim, left, top, width, height;
  while (f >> claim >> left >> top >> width >> height) {
    claim_positions[claim] = std::vector<std::pair<int, int>>();

    for (int i = 0; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
        auto key = std::make_pair(left + j, top + i);
        claim_positions[claim].push_back(key);

        if (pos_count.find(key) != pos_count.end()) {
          pos_count[key] += 1;
        } else {
          pos_count[key] = 1;
        }
      }
    }
  }

  // for each claim and its list of positions, find claim that
  // has overlap count of 1 for each position.
  for (auto kv : claim_positions) {
    int claim = kv.first;
    std::vector<std::pair<int, int>> pos_list = kv.second;

    bool intact = true;
    for (std::pair<int, int> pos : pos_list) {
      if (pos_count.find(pos) != pos_count.end() && pos_count[pos] > 1) {
        intact = false;
        break;
      }
    }
    if (intact) {
      return claim;
    }
  }

  throw("No intact claim found.");
}


int main() {
  std::cout << part1() << std::endl;
  std::cout << part2() << std::endl;

  return 0;
}
