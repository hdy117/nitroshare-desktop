/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Nathan Osman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 **/

#include <QStringList>

#include "version.h"

Version::Version(const QString &versionString)
    : mMajor(0),
      mMinor(0),
      mPatch(0)
{
    // Split into components and assign them to the correct member
    QStringList components = versionString.split('.');

    mMajor = components.at(0).toInt();
    if(components.count() > 1) {
        mMinor = components.at(1).toInt();
    }
    if(components.count() > 2) {
        mPatch = components.at(2).toInt();
    }
}

Version::Version(int major, int minor, int patch)
    : mMajor(major),
      mMinor(minor),
      mPatch(patch)
{
}

bool Version::operator==(const Version &other) const
{
    return mMajor == other.mMajor &&
           mMinor == other.mMinor &&
           mPatch == other.mPatch;
}

bool Version::operator!=(const Version &other) const
{
    return !(*this == other);
}

bool Version::operator<(const Version &other) const
{
    return mMajor < other.mMajor ||
           (mMajor == other.mMajor && mMinor < other.mMinor) ||
           (mMajor == other.mMajor && mMinor == other.mMinor && mPatch < other.mPatch);
}

bool Version::operator>(const Version &other) const
{
    return !(*this < other || *this == other);
}

bool Version::operator>=(const Version &other) const
{
    return !(*this < other);
}

bool Version::operator<=(const Version &other) const
{
    return !(*this > other);
}
