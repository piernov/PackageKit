/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2007 Richard Hughes <richard@hughsie.com>
 *
 * Licensed under the GNU General Public License Version 2
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
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __PK_PACKAGE_LIST_H
#define __PK_PACKAGE_LIST_H

#include <glib-object.h>
#include <pk-enum.h>

G_BEGIN_DECLS

#define PK_TYPE_PACKAGE_LIST		(pk_package_list_get_type ())
#define PK_PACKAGE_LIST(o)		(G_TYPE_CHECK_INSTANCE_CAST ((o), PK_TYPE_PACKAGE_LIST, PkPackageList))
#define PK_PACKAGE_LIST_CLASS(k)	(G_TYPE_CHECK_CLASS_CAST((k), PK_TYPE_PACKAGE_LIST, PkPackageListClass))
#define PK_IS_PACKAGE_LIST(o)		(G_TYPE_CHECK_INSTANCE_TYPE ((o), PK_TYPE_PACKAGE_LIST))
#define PK_IS_PACKAGE_LIST_CLASS(k)	(G_TYPE_CHECK_CLASS_TYPE ((k), PK_TYPE_PACKAGE_LIST))
#define PK_PACKAGE_LIST_GET_CLASS(o)	(G_TYPE_INSTANCE_GET_CLASS ((o), PK_TYPE_PACKAGE_LIST, PkPackageListClass))

typedef struct PkPackageListPrivate PkPackageListPrivate;

typedef struct
{
	 GObject		 parent;
	 PkPackageListPrivate	*priv;
} PkPackageList;

typedef struct
{
	GObjectClass	parent_class;
} PkPackageListClass;

typedef struct
{
	PkInfoEnum		 info;
	gchar			*package_id;
	gchar			*summary;
} PkPackageListItem;

GType		 pk_package_list_get_type		(void);
PkPackageList	*pk_package_list_new			(void);
gboolean	 pk_package_list_add			(PkPackageList		*plist,
							 PkInfoEnum		 info,
							 const gchar		*package_id,
							 const gchar		*summary);
gboolean	 pk_package_list_contains		(PkPackageList		*plist,
							 const gchar		*package_id);
gchar		*pk_package_list_get_string		(PkPackageList		*plist);
GPtrArray	*pk_package_list_get_buffer		(PkPackageList		*plist);
gboolean	 pk_package_list_clear			(PkPackageList		*plist);

G_END_DECLS

#endif /* __PK_PACKAGE_LIST_H */
