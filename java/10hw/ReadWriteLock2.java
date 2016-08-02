/*
Copyright (C) 2002,2006 Hiroshi Yuki.
http://www.hyuki.com/dp/dp2.html
hyuki@hyuki.com

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it freely,
subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim
that you wrote the original software. If you use this software in a product,
an acknowledgment in the product documentation would be appreciated but is not
required.

2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.

3. This notice may not be removed or altered from any source distribution.
 */

public final class ReadWriteLock2 {
	private int readingReaders = 0;
	private int writingWriters = 0;
	
	public synchronized void readLock() throws InterruptedException {
		while (writingWriters > 0) {
			wait();
		}
		readingReaders++;
	}
	
	public synchronized void readUnlock() {
		readingReaders--;
		notifyAll();
	}
	
	public synchronized void writeLock() throws InterruptedException {    	
		while (readingReaders > 0 || writingWriters > 0) {
			wait();
		}
		writingWriters++; 
	}
	
	public synchronized void writeUnlock() {
		writingWriters--;
		notifyAll();
	}
}
