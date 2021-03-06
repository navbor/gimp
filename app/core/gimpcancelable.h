/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995-1997 Spencer Kimball and Peter Mattis
 *
 * gimpcancelable.h
 * Copyright (C) 2018 Ell
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GIMP_CANCELABLE_H__
#define __GIMP_CANCELABLE_H__


#define GIMP_TYPE_CANCELABLE               (gimp_cancelable_get_type ())
#define GIMP_IS_CANCELABLE(obj)            (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GIMP_TYPE_CANCELABLE))
#define GIMP_CANCELABLE(obj)               (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIMP_TYPE_CANCELABLE, GimpCancelable))
#define GIMP_CANCELABLE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), GIMP_TYPE_CANCELABLE, GimpCancelableInterface))


typedef struct _GimpCancelableInterface GimpCancelableInterface;

struct _GimpCancelableInterface
{
  GTypeInterface base_iface;

  /*  signals  */
  void   (* cancel) (GimpCancelable *cancelable);
};


GType   gimp_cancelable_get_type (void) G_GNUC_CONST;

void    gimp_cancelable_cancel   (GimpCancelable *cancelable);


#endif  /* __GIMP_CANCELABLE_H__ */
