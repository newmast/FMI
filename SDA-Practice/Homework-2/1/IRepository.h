#pragma once

/*
 * Abstraction over the database layer.
 */
template<typename T>
class IRepository {
public:
  virtual T* find(long long id) = 0;
  virtual bool update(T entry) = 0;
  virtual bool remove(long long id) = 0;
};
