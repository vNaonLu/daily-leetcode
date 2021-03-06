#ifndef __LIST_NODE_H_
#define __LIST_NODE_H_

#include <initializer_list>
#include <iostream>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
struct ListNode;

template <typename... _type>
using enable_if_listnode_t = std::enable_if_t<(... && std::is_same_v<_type, ListNode *>), size_t>;

struct ListNode final {
  /// for leetcode usage
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  ~ListNode() {}

  /// for project usage
  typedef pair<int, int> _listnode_data;

  static ListNode*
  _build_list(vector<ListNode*> &v, const int &repeat) noexcept {
    if (v.empty()) return nullptr;
    for (int i = 0; i < v.size() - 1; ++i)
      v[i]->next = v[i + 1];
    if (repeat >= 0) v.back()->next = v[repeat];
    return v.front();
  }

  inline vector<_listnode_data>
  _data() const noexcept {
    unordered_map<uint64_t, int> _memo; /// avoid repeat
    vector<_listnode_data>  _data;
    const ListNode          *_p = this;
    size_t                  idx = 0;
    while(nullptr != _p) {
      if(_memo.count(reinterpret_cast<uint64_t>(_p))) {
        _data.emplace_back(_p->val,
                           _memo.at(reinterpret_cast<uint64_t>(_p)));
        break;
      } else {
        _data.emplace_back(_p->val, idx);
        _memo.insert(make_pair(reinterpret_cast<uint64_t>(_p),
                               idx++));
      }
      _p = _p->next;
    }
    return _data;
  }

  inline static ListNode *
  generate(const vector<int> &v, const int &repeat = -1) {
    assert(repeat == -1 || repeat < v.size());
    if (v.empty()) return nullptr;
    vector<ListNode*> dummy;
    for (int i = 0; i < v.size(); ++i)
      dummy.emplace_back(new ListNode(v[i]));
    return _build_list(dummy, repeat);
  }

  template <typename... _type> inline static
  enable_if_listnode_t<_type...> release(_type... nodes) noexcept {
    vector<ListNode *> _variadic_nodes = {nodes...};
    unordered_set<ListNode *> _cand_to_del;
    for (auto node : _variadic_nodes) {
      while (nullptr != node) {
        if (_cand_to_del.count(node)) break;
        _cand_to_del.insert(node);
        node = node->next;
      }
    }
    for (auto it = _cand_to_del.begin(); it != _cand_to_del.end(); ++it)
      delete *it;
    return _cand_to_del.size();
  }
};


inline bool
operator==(const ListNode &lhs, const ListNode &rhs) noexcept {
  auto _ldata = lhs._data(),
       _rdata = rhs._data();
  return _ldata == _rdata;
}

#ifdef EXPECT_EQ
#define EXPECT_LISTNODE_EQ(val1, val2)          \
{                                               \
  ListNode *actual = val1, *expect = val2;      \
  if (actual != nullptr && expect != nullptr) { \
    EXPECT_EQ(*actual, *expect);                \
  } else {                                      \
    EXPECT_EQ(actual, expect);                  \
  }                                             \
}
#endif

#endif