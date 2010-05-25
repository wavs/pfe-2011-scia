
template<typename T>
inline bool BB2<T>::IsPosIn(const Vector<2, T>& parPos) const
{
  return (MMin.x() <= parPos.x() &&
          MMin.y() <= parPos.y() &&
          MMax.x() >= parPos.x() &&
          MMax.y() >= parPos.y());
}
