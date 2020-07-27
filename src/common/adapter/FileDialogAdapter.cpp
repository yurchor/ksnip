/*
 * Copyright (C) 2020 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "FileDialogAdapter.h"

FileDialogAdapter::FileDialogAdapter()
{
#if defined(__linux__)
	CommandRunner commandRunner;
	mIsSnap = commandRunner.isEnvironmentVariableSet(QStringLiteral("SNAP"));
#endif
}

QString FileDialogAdapter::getExistingDirectory(QWidget *parent, const QString &title, const QString &directory)
{
#if defined(__linux__)
	if (mIsSnap) {
		return QFileDialog::getExistingDirectory(parent, title, directory, QFileDialog::DontUseNativeDialog);
	} else {
		return QFileDialog::getExistingDirectory(parent, title, directory);
	}
#endif

#if  defined(_WIN32) || defined(__APPLE__)
	return QFileDialog::getExistingDirectory(parent, title, directory);
#endif
}

QString FileDialogAdapter::getOpenFileName(QWidget *parent, const QString &title, const QString &directory)
{
#if defined(__linux__)
	if (mIsSnap) {
		return QFileDialog::getOpenFileName(parent, title, directory, nullptr, nullptr, QFileDialog::DontUseNativeDialog);
	} else {
		return QFileDialog::getOpenFileName(parent, title, directory);
	}
#endif

#if  defined(_WIN32) || defined(__APPLE__)
	return QFileDialog::getOpenFileName(parent, title, directory);
#endif
}