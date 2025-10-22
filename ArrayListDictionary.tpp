/*
TODO List:
[ ] bin iter
[ ] bin rec
[x] seq iter
[x] seq rec
*/
template <typename Key, typename Val>
unsigned ArrayListDictionary<Key, Val>::numComps = 0;

template <typename Key, typename Val>
ArrayListDictionary<Key, Val>::ArrayListDictionary(int i)
: list(new ArrayList<Record>(i)) { }

template <typename Key, typename Val>
ArrayListDictionary<Key, Val>::ArrayListDictionary(const ArrayListDictionary<Key, Val>& copyObj) {
    copy(copyObj);
}

template <typename Key, typename Val>
ArrayListDictionary<Key, Val>& ArrayListDictionary<Key, Val>::operator=(const ArrayListDictionary<Key, Val>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename Key, typename Val>
ArrayListDictionary<Key, Val>::~ArrayListDictionary() {
    delete list;
}

template <typename Key, typename Val>
Val ArrayListDictionary<Key, Val>::binSearchIter(const Key& target, int left, int right) const {
    // TODO
    while(left <= right){
		numComps++;
        int s = (left+right)/2;
		Record pair = list->getElement(s);
        if(pair.k == target){
            return pair.v;
        }
        else if(target > pair.k){
			numComps++;
			left = s + 1;
		}
        else{
			numComps++;
			right = s - 1;
		}
    }
    throw -1;
}

template <typename Key, typename Val>
Val ArrayListDictionary<Key, Val>::binSearchRec(const Key& target, int left, int right) const {
    // TODO
    if(left > right){
        numComps++;
        throw -1;
    }
    numComps++;
    int s = (left+right)/2;
	Record pair = list->getElement(s);
    if(pair.k == target){
        return pair.v;
    }
    else if (target > pair.k){
        numComps++;
        return binSearchRec(target, s + 1, right);
    }
    else{
        numComps++;
        return binSearchRec(target, left, s - 1);
    }
}

template <typename Key, typename Val>
void ArrayListDictionary<Key, Val>::clear() {
    list->clear();
}

template <typename Key, typename Val>
void ArrayListDictionary<Key, Val>::copy(const ArrayListDictionary<Key, Val>& copyObj) {
    list = new ArrayList<Record>(*copyObj.list);
}

template <typename Key, typename Val>
Val ArrayListDictionary<Key, Val>::find(const Key& k) const {
    numComps = 0;

    try {
        // return seqSearchIter(k);
        // return seqSearchRec(k);
        // return binSearchIter(k, 0, list->getLength() - 1);
        return binSearchRec(k, 0, list->getLength() - 1);
    }
    catch (...) {
        throw string("find: error, unsuccessful search, target key not found");
    }
}

template <typename Key, typename Val>
unsigned ArrayListDictionary<Key, Val>::getNumComps() {
    return numComps;
}

template <typename Key, typename Val>
void ArrayListDictionary<Key, Val>::insert(const Key& k, const Val& v) {
    list->append(Record(k, v));
}

template <typename Key, typename Val>
void ArrayListDictionary<Key, Val>::remove(const Key& k) {
    bool flag = false;

    for (int i = 0; i < list->getLength(); i++) {
        if (list->getElement(i).k == k) {
            list->remove(i);
            flag = true;
            break;
        }
    }

    if (!flag) {
        throw string("remove: error, unable to find record with matching key to remove");
    }
}

template <typename Key, typename Val>
Val ArrayListDictionary<Key, Val>::seqSearchIter(const Key& target) const {
    // TODO

    // going through the entire list element by element

    int len = list->getLength();
    for(int i = 0; i < len; i++){
		numComps++;
		Record pair = list->getElement(i);
        if (pair.k == target){
            return pair.v;
        }
    }
	throw string("error: Key not in dict");

}

template <typename Key, typename Val>
Val ArrayListDictionary<Key, Val>::seqSearchRec(const Key& target, int i) const {
    // TODO
	if(i == size()) throw string ("error: key not in dict");
	numComps++;
	if(list->getElement(i).k == target) return list->getElement(i).v;
		
	return seqSearchRec(target, i + 1);
}

template <typename Key, typename Val>
int ArrayListDictionary<Key, Val>::size() const {
    return list->getLength();
}
