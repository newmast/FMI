#pragma once

/*
 * Abstraction over the database layer.
 */
template<typename T>
class IRepository {
public:
  virtual void create(T entry) = 0;
  virtual T* find(int id) = 0;
};
