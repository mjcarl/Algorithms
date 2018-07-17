//lock_guard(const lock_guard&) = delete; 
//lock_guard& operator=(const lock_guard&) = delete;
//�����˿������캯���͸�ֵ���캯��.��֤�� lock_guard ���������Ȩ���ᱻת��.

template<class _Mutex>

class lock_guard
{   // class with destructor that unlocks mutex
	public:
		typedef _Mutex mutex_type;

		explicit lock_guard(_Mutex& _Mtx)
			: _MyMutex(_Mtx)
		{   // construct and lock
			_MyMutex.lock();
		}

		lock_guard(_Mutex& _Mtx, adopt_lock_t)
			: _MyMutex(_Mtx)
		{   // construct but don't lock
		}

		~lock_guard() _NOEXCEPT
		{   // unlock
			_MyMutex.unlock();
		}

		lock_guard (const lock_guard&) = delete;
		lock_guard& operator=(const lock_guard&) = delete;

	private:
		_Mutex& _MyMutex;
}; 
