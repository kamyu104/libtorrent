// libTorrent - BitTorrent library
// Copyright (C) 2005, Jari Sundell
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// Contact:  Jari Sundell <jaris@ifi.uio.no>
//
//           Skomakerveien 33
//           3185 Skoppum, NORWAY

#ifndef LIBTORRENT_UTILS_RANGES_H
#define LIBTORRENT_UTILS_RANGES_H

#include <inttypes.h>
#include <vector>

namespace torrent {

class Ranges : private std::vector<std::pair<uint32_t, uint32_t> > {
public:
  typedef std::vector<std::pair<uint32_t, uint32_t> > Base;

  using Base::value_type;

  using Base::iterator;
  using Base::reverse_iterator;
  using Base::clear;
  using Base::size;

  using Base::begin;
  using Base::end;
  using Base::rbegin;
  using Base::rend;

  void                insert(uint32_t first, uint32_t last) { insert(std::make_pair(first, last)); }
  void                erase(uint32_t first, uint32_t last)  { erase(std::make_pair(first, last)); }

  void                insert(value_type r);
  void                erase(value_type r);

  // Find the first ranges that has an end greater than index.
  iterator            find(uint32_t index);

  // Use find with no closest match.
  bool                has(uint32_t index);

  // Remove ranges in r from this.
  Ranges&             intersect(Ranges& r);
};

}

#endif