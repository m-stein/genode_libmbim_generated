
/* GENERATED CODE... DO NOT EDIT */

/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 * Copyright (C) 2013 - 2018 Aleksander Morgado <aleksander@aleksander.es>
 */


#include <string.h>

#include "mbim-basic-connect.h"
#include "mbim-message-private.h"
#include "mbim-enum-types.h"
#include "mbim-error-types.h"
#include "mbim-device.h"
#include "mbim-utils.h"

/*****************************************************************************/
/* Struct: MbimPinDesc */

static void
_mbim_pin_desc_free (MbimPinDesc *var)
{
    if (!var)
        return;

    g_free (var);
}

void
mbim_pin_desc_free (MbimPinDesc *var)
{
    _mbim_pin_desc_free (var);
}

static MbimPinDesc *
_mbim_message_read_mbim_pin_desc_struct (
    const MbimMessage *self,
    guint32 relative_offset,
    guint32 *bytes_read,
    GError **error)
{
    gboolean success = FALSE;
    MbimPinDesc *out;
    guint32 offset = relative_offset;

    g_assert (self != NULL);

    out = g_new0 (MbimPinDesc, 1);

    if (!_mbim_message_read_guint32 (self, offset, &out->pin_mode, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->pin_format, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->pin_length_min, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->pin_length_max, error))
        goto out;
    offset += 4;

    success = TRUE;

 out:
    if (success) {
        if (bytes_read)
            *bytes_read = (offset - relative_offset);
        return out;
    }

    g_free (out);
    return NULL;
}

static gchar *
_mbim_message_print_mbim_pin_desc_struct (
    const MbimPinDesc *self,
    const gchar *line_prefix)
{
    GString *str;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  PinMode = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->pin_mode);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  PinFormat = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->pin_format);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  PinLengthMin = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->pin_length_min);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  PinLengthMax = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->pin_length_max);
    }
    g_string_append (str, "\n");
    return g_string_free (str, FALSE);
}

static GByteArray *
_mbim_pin_desc_struct_new (const MbimPinDesc *value)
{
    MbimStructBuilder *builder;

    g_assert (value != NULL);

    builder = _mbim_struct_builder_new ();
    _mbim_struct_builder_append_guint32 (builder, value->pin_mode);
    _mbim_struct_builder_append_guint32 (builder, value->pin_format);
    _mbim_struct_builder_append_guint32 (builder, value->pin_length_min);
    _mbim_struct_builder_append_guint32 (builder, value->pin_length_max);

    return _mbim_struct_builder_complete (builder);
}

static void
_mbim_struct_builder_append_mbim_pin_desc_struct (
    MbimStructBuilder *builder,
    const MbimPinDesc *value)
{
    GByteArray *raw;

    raw = _mbim_pin_desc_struct_new (value);
    g_byte_array_append (builder->fixed_buffer, raw->data, raw->len);
    g_byte_array_unref (raw);
}

static void
_mbim_message_command_builder_append_mbim_pin_desc_struct (
    MbimMessageCommandBuilder *builder,
    const MbimPinDesc *value)
{
    _mbim_struct_builder_append_mbim_pin_desc_struct (builder->contents_builder, value);
}

static void
_mbim_struct_builder_append_mbim_pin_desc_struct_array (
    MbimStructBuilder *builder,
    const MbimPinDesc *const *values,
    guint32 n_values,
    gboolean refs)
{
    guint32 offset;
    guint32 i;
    GByteArray *raw_all = NULL;

    if (!refs) {
        for (i = 0; i < n_values; i++) {
            GByteArray *raw;

            raw = _mbim_pin_desc_struct_new (values[i]);
            if (!raw_all)
                raw_all = raw;
            else {
                g_byte_array_append (raw_all, raw->data, raw->len);
                g_byte_array_unref (raw);
            }
        }

        if (!raw_all) {
            offset = 0;
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
        } else {
            guint32 offset_offset;

            /* Offset of the offset */
            offset_offset = builder->fixed_buffer->len;
            /* Length *not* in LE yet */
            offset = builder->variable_buffer->len;
            /* Add the offset value */
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
            /* Configure the value to get updated */
            g_array_append_val (builder->offsets, offset_offset);
            /* Add the final array itself */
            g_byte_array_append (builder->variable_buffer, raw_all->data, raw_all->len);
            g_byte_array_unref (raw_all);
        }
    } else {
        for (i = 0; i < n_values; i++) {
            guint32 length;
            guint32 offset_offset;
            GByteArray *raw;

            raw = _mbim_pin_desc_struct_new (values[i]);
            g_assert (raw->len > 0);

            /* Offset of the offset */
            offset_offset = builder->fixed_buffer->len;

            /* Length *not* in LE yet */
            offset = builder->variable_buffer->len;
            /* Add the offset value */
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
            /* Configure the value to get updated */
            g_array_append_val (builder->offsets, offset_offset);

            /* Add the length value */
            length = GUINT32_TO_LE (raw->len);
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&length, sizeof (length));

            /* And finally, the bytearray itself to the variable buffer */
            g_byte_array_append (builder->variable_buffer, (const guint8 *)raw->data, (guint)raw->len);
            g_byte_array_unref (raw);
        }
    }
}

static void
_mbim_message_command_builder_append_mbim_pin_desc_struct_array (
    MbimMessageCommandBuilder *builder,
    const MbimPinDesc *const *values,
    guint32 n_values,
    gboolean refs)
{
    _mbim_struct_builder_append_mbim_pin_desc_struct_array (builder->contents_builder, values, n_values, refs);
}

/*****************************************************************************/
/* Struct: MbimProvider */

static void
_mbim_provider_free (MbimProvider *var)
{
    if (!var)
        return;

    g_free (var->provider_id);
    g_free (var->provider_name);
    g_free (var);
}

void
mbim_provider_free (MbimProvider *var)
{
    _mbim_provider_free (var);
}

void
mbim_provider_array_free (MbimProviderArray *array)
{
    guint32 i;

    if (!array)
        return;

    for (i = 0; array[i]; i++)
        _mbim_provider_free (array[i]);
    g_free (array);
}

static MbimProvider *
_mbim_message_read_mbim_provider_struct (
    const MbimMessage *self,
    guint32 relative_offset,
    guint32 *bytes_read,
    GError **error)
{
    gboolean success = FALSE;
    MbimProvider *out;
    guint32 offset = relative_offset;

    g_assert (self != NULL);

    out = g_new0 (MbimProvider, 1);

    if (!_mbim_message_read_string (self, relative_offset, offset, &out->provider_id, error))
        goto out;
    offset += 8;

    if (!_mbim_message_read_guint32 (self, offset, &out->provider_state, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_string (self, relative_offset, offset, &out->provider_name, error))
        goto out;
    offset += 8;

    if (!_mbim_message_read_guint32 (self, offset, &out->cellular_class, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->rssi, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->error_rate, error))
        goto out;
    offset += 4;

    success = TRUE;

 out:
    if (success) {
        if (bytes_read)
            *bytes_read = (offset - relative_offset);
        return out;
    }

    g_free (out->provider_id);
    g_free (out->provider_name);
    g_free (out);
    return NULL;
}

static gboolean
_mbim_message_read_mbim_provider_struct_array (
    const MbimMessage *self,
    guint32 array_size,
    guint32 relative_offset_array_start,
    gboolean refs,
    MbimProviderArray **out_array,
    GError **error)
{
    GError *inner_error = NULL;
    MbimProviderArray *out;
    guint32 i;
    guint32 offset;

    if (!array_size) {
        *out_array = NULL;
        return TRUE;
    }

    out = g_new0 (MbimProvider *, array_size + 1);

    if (!refs) {
        _mbim_message_read_guint32 (self, relative_offset_array_start, &offset, &inner_error);
        for (i = 0; !inner_error && (i < array_size); i++, offset += 0)
            out[i] = _mbim_message_read_mbim_provider_struct (self, offset, NULL, &inner_error);
    } else {
        offset = relative_offset_array_start;
        for (i = 0; !inner_error && (i < array_size); i++, offset += 8) {
            guint32 tmp_offset;

            if (_mbim_message_read_guint32 (self, offset, &tmp_offset, &inner_error))
                out[i] = _mbim_message_read_mbim_provider_struct (self, tmp_offset, NULL, &inner_error);
        }
    }

    if (!inner_error) {
        *out_array = out;
        return TRUE;
    }

    mbim_provider_array_free (out);
    g_propagate_error (error, inner_error);
    return FALSE;
}

static gchar *
_mbim_message_print_mbim_provider_struct (
    const MbimProvider *self,
    const gchar *line_prefix)
{
    GString *str;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ProviderId = ", line_prefix);
    {
        g_string_append_printf (str, "'%s'", self->provider_id);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  ProviderState = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->provider_state);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  ProviderName = ", line_prefix);
    {
        g_string_append_printf (str, "'%s'", self->provider_name);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  CellularClass = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->cellular_class);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Rssi = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->rssi);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  ErrorRate = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->error_rate);
    }
    g_string_append (str, "\n");
    return g_string_free (str, FALSE);
}

static GByteArray *
_mbim_provider_struct_new (const MbimProvider *value)
{
    MbimStructBuilder *builder;

    g_assert (value != NULL);

    builder = _mbim_struct_builder_new ();
    _mbim_struct_builder_append_string (builder, value->provider_id);
    _mbim_struct_builder_append_guint32 (builder, value->provider_state);
    _mbim_struct_builder_append_string (builder, value->provider_name);
    _mbim_struct_builder_append_guint32 (builder, value->cellular_class);
    _mbim_struct_builder_append_guint32 (builder, value->rssi);
    _mbim_struct_builder_append_guint32 (builder, value->error_rate);

    return _mbim_struct_builder_complete (builder);
}

static void
_mbim_struct_builder_append_mbim_provider_struct (
    MbimStructBuilder *builder,
    const MbimProvider *value)
{
    GByteArray *raw;

    raw = _mbim_provider_struct_new (value);
    g_byte_array_append (builder->fixed_buffer, raw->data, raw->len);
    g_byte_array_unref (raw);
}

static void
_mbim_message_command_builder_append_mbim_provider_struct (
    MbimMessageCommandBuilder *builder,
    const MbimProvider *value)
{
    _mbim_struct_builder_append_mbim_provider_struct (builder->contents_builder, value);
}

static void
_mbim_struct_builder_append_mbim_provider_struct_array (
    MbimStructBuilder *builder,
    const MbimProvider *const *values,
    guint32 n_values,
    gboolean refs)
{
    guint32 offset;
    guint32 i;
    GByteArray *raw_all = NULL;

    if (!refs) {
        for (i = 0; i < n_values; i++) {
            GByteArray *raw;

            raw = _mbim_provider_struct_new (values[i]);
            if (!raw_all)
                raw_all = raw;
            else {
                g_byte_array_append (raw_all, raw->data, raw->len);
                g_byte_array_unref (raw);
            }
        }

        if (!raw_all) {
            offset = 0;
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
        } else {
            guint32 offset_offset;

            /* Offset of the offset */
            offset_offset = builder->fixed_buffer->len;
            /* Length *not* in LE yet */
            offset = builder->variable_buffer->len;
            /* Add the offset value */
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
            /* Configure the value to get updated */
            g_array_append_val (builder->offsets, offset_offset);
            /* Add the final array itself */
            g_byte_array_append (builder->variable_buffer, raw_all->data, raw_all->len);
            g_byte_array_unref (raw_all);
        }
    } else {
        for (i = 0; i < n_values; i++) {
            guint32 length;
            guint32 offset_offset;
            GByteArray *raw;

            raw = _mbim_provider_struct_new (values[i]);
            g_assert (raw->len > 0);

            /* Offset of the offset */
            offset_offset = builder->fixed_buffer->len;

            /* Length *not* in LE yet */
            offset = builder->variable_buffer->len;
            /* Add the offset value */
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
            /* Configure the value to get updated */
            g_array_append_val (builder->offsets, offset_offset);

            /* Add the length value */
            length = GUINT32_TO_LE (raw->len);
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&length, sizeof (length));

            /* And finally, the bytearray itself to the variable buffer */
            g_byte_array_append (builder->variable_buffer, (const guint8 *)raw->data, (guint)raw->len);
            g_byte_array_unref (raw);
        }
    }
}

static void
_mbim_message_command_builder_append_mbim_provider_struct_array (
    MbimMessageCommandBuilder *builder,
    const MbimProvider *const *values,
    guint32 n_values,
    gboolean refs)
{
    _mbim_struct_builder_append_mbim_provider_struct_array (builder->contents_builder, values, n_values, refs);
}

/*****************************************************************************/
/* Struct: MbimProvisionedContextElement */

static void
_mbim_provisioned_context_element_free (MbimProvisionedContextElement *var)
{
    if (!var)
        return;

    g_free (var->access_string);
    g_free (var->user_name);
    g_free (var->password);
    g_free (var);
}

void
mbim_provisioned_context_element_array_free (MbimProvisionedContextElementArray *array)
{
    guint32 i;

    if (!array)
        return;

    for (i = 0; array[i]; i++)
        _mbim_provisioned_context_element_free (array[i]);
    g_free (array);
}

static MbimProvisionedContextElement *
_mbim_message_read_mbim_provisioned_context_element_struct (
    const MbimMessage *self,
    guint32 relative_offset,
    guint32 *bytes_read,
    GError **error)
{
    gboolean success = FALSE;
    MbimProvisionedContextElement *out;
    guint32 offset = relative_offset;

    g_assert (self != NULL);

    out = g_new0 (MbimProvisionedContextElement, 1);

    if (!_mbim_message_read_guint32 (self, offset, &out->context_id, error))
        goto out;
    offset += 4;

    {
        const MbimUuid *tmp;

        if (!_mbim_message_read_uuid (self, offset, &tmp, error))
            goto out;
        memcpy (&(out->context_type), tmp, 16);
        offset += 16;
    }

    if (!_mbim_message_read_string (self, relative_offset, offset, &out->access_string, error))
        goto out;
    offset += 8;

    if (!_mbim_message_read_string (self, relative_offset, offset, &out->user_name, error))
        goto out;
    offset += 8;

    if (!_mbim_message_read_string (self, relative_offset, offset, &out->password, error))
        goto out;
    offset += 8;

    if (!_mbim_message_read_guint32 (self, offset, &out->compression, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->auth_protocol, error))
        goto out;
    offset += 4;

    success = TRUE;

 out:
    if (success) {
        if (bytes_read)
            *bytes_read = (offset - relative_offset);
        return out;
    }

    g_free (out->access_string);
    g_free (out->user_name);
    g_free (out->password);
    g_free (out);
    return NULL;
}

static gboolean
_mbim_message_read_mbim_provisioned_context_element_struct_array (
    const MbimMessage *self,
    guint32 array_size,
    guint32 relative_offset_array_start,
    gboolean refs,
    MbimProvisionedContextElementArray **out_array,
    GError **error)
{
    GError *inner_error = NULL;
    MbimProvisionedContextElementArray *out;
    guint32 i;
    guint32 offset;

    if (!array_size) {
        *out_array = NULL;
        return TRUE;
    }

    out = g_new0 (MbimProvisionedContextElement *, array_size + 1);

    if (!refs) {
        _mbim_message_read_guint32 (self, relative_offset_array_start, &offset, &inner_error);
        for (i = 0; !inner_error && (i < array_size); i++, offset += 0)
            out[i] = _mbim_message_read_mbim_provisioned_context_element_struct (self, offset, NULL, &inner_error);
    } else {
        offset = relative_offset_array_start;
        for (i = 0; !inner_error && (i < array_size); i++, offset += 8) {
            guint32 tmp_offset;

            if (_mbim_message_read_guint32 (self, offset, &tmp_offset, &inner_error))
                out[i] = _mbim_message_read_mbim_provisioned_context_element_struct (self, tmp_offset, NULL, &inner_error);
        }
    }

    if (!inner_error) {
        *out_array = out;
        return TRUE;
    }

    mbim_provisioned_context_element_array_free (out);
    g_propagate_error (error, inner_error);
    return FALSE;
}

static gchar *
_mbim_message_print_mbim_provisioned_context_element_struct (
    const MbimProvisionedContextElement *self,
    const gchar *line_prefix)
{
    GString *str;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ContextId = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->context_id);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  ContextType = ", line_prefix);
    {
        gchar *tmpstr;

        tmpstr = mbim_uuid_get_printable (&(self->context_type));
        g_string_append_printf (str, "'%s'", tmpstr);
        g_free (tmpstr);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  AccessString = ", line_prefix);
    {
        g_string_append_printf (str, "'%s'", self->access_string);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  UserName = ", line_prefix);
    {
        g_string_append_printf (str, "'%s'", self->user_name);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Password = ", line_prefix);
    {
        g_string_append_printf (str, "'%s'", self->password);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Compression = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->compression);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  AuthProtocol = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->auth_protocol);
    }
    g_string_append (str, "\n");
    return g_string_free (str, FALSE);
}

static GByteArray *
_mbim_provisioned_context_element_struct_new (const MbimProvisionedContextElement *value)
{
    MbimStructBuilder *builder;

    g_assert (value != NULL);

    builder = _mbim_struct_builder_new ();
    _mbim_struct_builder_append_guint32 (builder, value->context_id);
    _mbim_struct_builder_append_uuid (builder, &(value->context_type));
    _mbim_struct_builder_append_string (builder, value->access_string);
    _mbim_struct_builder_append_string (builder, value->user_name);
    _mbim_struct_builder_append_string (builder, value->password);
    _mbim_struct_builder_append_guint32 (builder, value->compression);
    _mbim_struct_builder_append_guint32 (builder, value->auth_protocol);

    return _mbim_struct_builder_complete (builder);
}

static void
_mbim_struct_builder_append_mbim_provisioned_context_element_struct (
    MbimStructBuilder *builder,
    const MbimProvisionedContextElement *value)
{
    GByteArray *raw;

    raw = _mbim_provisioned_context_element_struct_new (value);
    g_byte_array_append (builder->fixed_buffer, raw->data, raw->len);
    g_byte_array_unref (raw);
}

static void
_mbim_message_command_builder_append_mbim_provisioned_context_element_struct (
    MbimMessageCommandBuilder *builder,
    const MbimProvisionedContextElement *value)
{
    _mbim_struct_builder_append_mbim_provisioned_context_element_struct (builder->contents_builder, value);
}

static void
_mbim_struct_builder_append_mbim_provisioned_context_element_struct_array (
    MbimStructBuilder *builder,
    const MbimProvisionedContextElement *const *values,
    guint32 n_values,
    gboolean refs)
{
    guint32 offset;
    guint32 i;
    GByteArray *raw_all = NULL;

    if (!refs) {
        for (i = 0; i < n_values; i++) {
            GByteArray *raw;

            raw = _mbim_provisioned_context_element_struct_new (values[i]);
            if (!raw_all)
                raw_all = raw;
            else {
                g_byte_array_append (raw_all, raw->data, raw->len);
                g_byte_array_unref (raw);
            }
        }

        if (!raw_all) {
            offset = 0;
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
        } else {
            guint32 offset_offset;

            /* Offset of the offset */
            offset_offset = builder->fixed_buffer->len;
            /* Length *not* in LE yet */
            offset = builder->variable_buffer->len;
            /* Add the offset value */
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
            /* Configure the value to get updated */
            g_array_append_val (builder->offsets, offset_offset);
            /* Add the final array itself */
            g_byte_array_append (builder->variable_buffer, raw_all->data, raw_all->len);
            g_byte_array_unref (raw_all);
        }
    } else {
        for (i = 0; i < n_values; i++) {
            guint32 length;
            guint32 offset_offset;
            GByteArray *raw;

            raw = _mbim_provisioned_context_element_struct_new (values[i]);
            g_assert (raw->len > 0);

            /* Offset of the offset */
            offset_offset = builder->fixed_buffer->len;

            /* Length *not* in LE yet */
            offset = builder->variable_buffer->len;
            /* Add the offset value */
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
            /* Configure the value to get updated */
            g_array_append_val (builder->offsets, offset_offset);

            /* Add the length value */
            length = GUINT32_TO_LE (raw->len);
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&length, sizeof (length));

            /* And finally, the bytearray itself to the variable buffer */
            g_byte_array_append (builder->variable_buffer, (const guint8 *)raw->data, (guint)raw->len);
            g_byte_array_unref (raw);
        }
    }
}

static void
_mbim_message_command_builder_append_mbim_provisioned_context_element_struct_array (
    MbimMessageCommandBuilder *builder,
    const MbimProvisionedContextElement *const *values,
    guint32 n_values,
    gboolean refs)
{
    _mbim_struct_builder_append_mbim_provisioned_context_element_struct_array (builder->contents_builder, values, n_values, refs);
}

/*****************************************************************************/
/* Struct: MbimIPv4Element */

static void
_mbim_ipv4_element_free (MbimIPv4Element *var)
{
    if (!var)
        return;

    g_free (var);
}

void
mbim_ipv4_element_array_free (MbimIPv4ElementArray *array)
{
    guint32 i;

    if (!array)
        return;

    for (i = 0; array[i]; i++)
        _mbim_ipv4_element_free (array[i]);
    g_free (array);
}

static MbimIPv4Element *
_mbim_message_read_mbim_ipv4_element_struct (
    const MbimMessage *self,
    guint32 relative_offset,
    guint32 *bytes_read,
    GError **error)
{
    gboolean success = FALSE;
    MbimIPv4Element *out;
    guint32 offset = relative_offset;

    g_assert (self != NULL);

    out = g_new0 (MbimIPv4Element, 1);

    if (!_mbim_message_read_guint32 (self, offset, &out->on_link_prefix_length, error))
        goto out;
    offset += 4;

    {
        const MbimIPv4 *tmp;

        if (!_mbim_message_read_ipv4 (self, offset, FALSE, &tmp, error))
            goto out;
        memcpy (&(out->ipv4_address), tmp, 4);
        offset += 4;
    }

    success = TRUE;

 out:
    if (success) {
        if (bytes_read)
            *bytes_read = (offset - relative_offset);
        return out;
    }

    g_free (out);
    return NULL;
}

static gboolean
_mbim_message_read_mbim_ipv4_element_struct_array (
    const MbimMessage *self,
    guint32 array_size,
    guint32 relative_offset_array_start,
    gboolean refs,
    MbimIPv4ElementArray **out_array,
    GError **error)
{
    GError *inner_error = NULL;
    MbimIPv4ElementArray *out;
    guint32 i;
    guint32 offset;

    if (!array_size) {
        *out_array = NULL;
        return TRUE;
    }

    out = g_new0 (MbimIPv4Element *, array_size + 1);

    if (!refs) {
        _mbim_message_read_guint32 (self, relative_offset_array_start, &offset, &inner_error);
        for (i = 0; !inner_error && (i < array_size); i++, offset += 8)
            out[i] = _mbim_message_read_mbim_ipv4_element_struct (self, offset, NULL, &inner_error);
    } else {
        offset = relative_offset_array_start;
        for (i = 0; !inner_error && (i < array_size); i++, offset += 8) {
            guint32 tmp_offset;

            if (_mbim_message_read_guint32 (self, offset, &tmp_offset, &inner_error))
                out[i] = _mbim_message_read_mbim_ipv4_element_struct (self, tmp_offset, NULL, &inner_error);
        }
    }

    if (!inner_error) {
        *out_array = out;
        return TRUE;
    }

    mbim_ipv4_element_array_free (out);
    g_propagate_error (error, inner_error);
    return FALSE;
}

static gchar *
_mbim_message_print_mbim_ipv4_element_struct (
    const MbimIPv4Element *self,
    const gchar *line_prefix)
{
    GString *str;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  OnLinkPrefixLength = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->on_link_prefix_length);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  IPv4Address = ", line_prefix);
    {
        g_autoptr(GInetAddress)  addr = NULL;
        g_autofree gchar        *tmpstr = NULL;

        addr = g_inet_address_new_from_bytes ((guint8 *)&(self->ipv4_address.addr), G_SOCKET_FAMILY_IPV4);
        tmpstr = g_inet_address_to_string (addr);
        g_string_append_printf (str, "'%s'", tmpstr);
    }
    g_string_append (str, "\n");
    return g_string_free (str, FALSE);
}

static GByteArray *
_mbim_ipv4_element_struct_new (const MbimIPv4Element *value)
{
    MbimStructBuilder *builder;

    g_assert (value != NULL);

    builder = _mbim_struct_builder_new ();
    _mbim_struct_builder_append_guint32 (builder, value->on_link_prefix_length);
    _mbim_struct_builder_append_ipv4 (builder, &value->ipv4_address, FALSE);

    return _mbim_struct_builder_complete (builder);
}

static void
_mbim_struct_builder_append_mbim_ipv4_element_struct (
    MbimStructBuilder *builder,
    const MbimIPv4Element *value)
{
    GByteArray *raw;

    raw = _mbim_ipv4_element_struct_new (value);
    g_byte_array_append (builder->fixed_buffer, raw->data, raw->len);
    g_byte_array_unref (raw);
}

static void
_mbim_message_command_builder_append_mbim_ipv4_element_struct (
    MbimMessageCommandBuilder *builder,
    const MbimIPv4Element *value)
{
    _mbim_struct_builder_append_mbim_ipv4_element_struct (builder->contents_builder, value);
}

static void
_mbim_struct_builder_append_mbim_ipv4_element_struct_array (
    MbimStructBuilder *builder,
    const MbimIPv4Element *const *values,
    guint32 n_values,
    gboolean refs)
{
    guint32 offset;
    guint32 i;
    GByteArray *raw_all = NULL;

    if (!refs) {
        for (i = 0; i < n_values; i++) {
            GByteArray *raw;

            raw = _mbim_ipv4_element_struct_new (values[i]);
            if (!raw_all)
                raw_all = raw;
            else {
                g_byte_array_append (raw_all, raw->data, raw->len);
                g_byte_array_unref (raw);
            }
        }

        if (!raw_all) {
            offset = 0;
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
        } else {
            guint32 offset_offset;

            /* Offset of the offset */
            offset_offset = builder->fixed_buffer->len;
            /* Length *not* in LE yet */
            offset = builder->variable_buffer->len;
            /* Add the offset value */
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
            /* Configure the value to get updated */
            g_array_append_val (builder->offsets, offset_offset);
            /* Add the final array itself */
            g_byte_array_append (builder->variable_buffer, raw_all->data, raw_all->len);
            g_byte_array_unref (raw_all);
        }
    } else {
        for (i = 0; i < n_values; i++) {
            guint32 length;
            guint32 offset_offset;
            GByteArray *raw;

            raw = _mbim_ipv4_element_struct_new (values[i]);
            g_assert (raw->len > 0);

            /* Offset of the offset */
            offset_offset = builder->fixed_buffer->len;

            /* Length *not* in LE yet */
            offset = builder->variable_buffer->len;
            /* Add the offset value */
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
            /* Configure the value to get updated */
            g_array_append_val (builder->offsets, offset_offset);

            /* Add the length value */
            length = GUINT32_TO_LE (raw->len);
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&length, sizeof (length));

            /* And finally, the bytearray itself to the variable buffer */
            g_byte_array_append (builder->variable_buffer, (const guint8 *)raw->data, (guint)raw->len);
            g_byte_array_unref (raw);
        }
    }
}

static void
_mbim_message_command_builder_append_mbim_ipv4_element_struct_array (
    MbimMessageCommandBuilder *builder,
    const MbimIPv4Element *const *values,
    guint32 n_values,
    gboolean refs)
{
    _mbim_struct_builder_append_mbim_ipv4_element_struct_array (builder->contents_builder, values, n_values, refs);
}

/*****************************************************************************/
/* Struct: MbimIPv6Element */

static void
_mbim_ipv6_element_free (MbimIPv6Element *var)
{
    if (!var)
        return;

    g_free (var);
}

void
mbim_ipv6_element_array_free (MbimIPv6ElementArray *array)
{
    guint32 i;

    if (!array)
        return;

    for (i = 0; array[i]; i++)
        _mbim_ipv6_element_free (array[i]);
    g_free (array);
}

static MbimIPv6Element *
_mbim_message_read_mbim_ipv6_element_struct (
    const MbimMessage *self,
    guint32 relative_offset,
    guint32 *bytes_read,
    GError **error)
{
    gboolean success = FALSE;
    MbimIPv6Element *out;
    guint32 offset = relative_offset;

    g_assert (self != NULL);

    out = g_new0 (MbimIPv6Element, 1);

    if (!_mbim_message_read_guint32 (self, offset, &out->on_link_prefix_length, error))
        goto out;
    offset += 4;

    {
        const MbimIPv6 *tmp;

        if (!_mbim_message_read_ipv6 (self, offset, FALSE, &tmp, error))
            goto out;
        memcpy (&(out->ipv6_address), tmp, 16);
        offset += 16;
    }

    success = TRUE;

 out:
    if (success) {
        if (bytes_read)
            *bytes_read = (offset - relative_offset);
        return out;
    }

    g_free (out);
    return NULL;
}

static gboolean
_mbim_message_read_mbim_ipv6_element_struct_array (
    const MbimMessage *self,
    guint32 array_size,
    guint32 relative_offset_array_start,
    gboolean refs,
    MbimIPv6ElementArray **out_array,
    GError **error)
{
    GError *inner_error = NULL;
    MbimIPv6ElementArray *out;
    guint32 i;
    guint32 offset;

    if (!array_size) {
        *out_array = NULL;
        return TRUE;
    }

    out = g_new0 (MbimIPv6Element *, array_size + 1);

    if (!refs) {
        _mbim_message_read_guint32 (self, relative_offset_array_start, &offset, &inner_error);
        for (i = 0; !inner_error && (i < array_size); i++, offset += 20)
            out[i] = _mbim_message_read_mbim_ipv6_element_struct (self, offset, NULL, &inner_error);
    } else {
        offset = relative_offset_array_start;
        for (i = 0; !inner_error && (i < array_size); i++, offset += 8) {
            guint32 tmp_offset;

            if (_mbim_message_read_guint32 (self, offset, &tmp_offset, &inner_error))
                out[i] = _mbim_message_read_mbim_ipv6_element_struct (self, tmp_offset, NULL, &inner_error);
        }
    }

    if (!inner_error) {
        *out_array = out;
        return TRUE;
    }

    mbim_ipv6_element_array_free (out);
    g_propagate_error (error, inner_error);
    return FALSE;
}

static gchar *
_mbim_message_print_mbim_ipv6_element_struct (
    const MbimIPv6Element *self,
    const gchar *line_prefix)
{
    GString *str;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  OnLinkPrefixLength = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->on_link_prefix_length);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  IPv6Address = ", line_prefix);
    {
        g_autoptr(GInetAddress)  addr = NULL;
        g_autofree gchar        *tmpstr = NULL;

        addr = g_inet_address_new_from_bytes ((guint8 *)&(self->ipv6_address.addr), G_SOCKET_FAMILY_IPV6);
        tmpstr = g_inet_address_to_string (addr);
        g_string_append_printf (str, "'%s'", tmpstr);
    }
    g_string_append (str, "\n");
    return g_string_free (str, FALSE);
}

static GByteArray *
_mbim_ipv6_element_struct_new (const MbimIPv6Element *value)
{
    MbimStructBuilder *builder;

    g_assert (value != NULL);

    builder = _mbim_struct_builder_new ();
    _mbim_struct_builder_append_guint32 (builder, value->on_link_prefix_length);
    _mbim_struct_builder_append_ipv6 (builder, &value->ipv6_address, FALSE);

    return _mbim_struct_builder_complete (builder);
}

static void
_mbim_struct_builder_append_mbim_ipv6_element_struct (
    MbimStructBuilder *builder,
    const MbimIPv6Element *value)
{
    GByteArray *raw;

    raw = _mbim_ipv6_element_struct_new (value);
    g_byte_array_append (builder->fixed_buffer, raw->data, raw->len);
    g_byte_array_unref (raw);
}

static void
_mbim_message_command_builder_append_mbim_ipv6_element_struct (
    MbimMessageCommandBuilder *builder,
    const MbimIPv6Element *value)
{
    _mbim_struct_builder_append_mbim_ipv6_element_struct (builder->contents_builder, value);
}

static void
_mbim_struct_builder_append_mbim_ipv6_element_struct_array (
    MbimStructBuilder *builder,
    const MbimIPv6Element *const *values,
    guint32 n_values,
    gboolean refs)
{
    guint32 offset;
    guint32 i;
    GByteArray *raw_all = NULL;

    if (!refs) {
        for (i = 0; i < n_values; i++) {
            GByteArray *raw;

            raw = _mbim_ipv6_element_struct_new (values[i]);
            if (!raw_all)
                raw_all = raw;
            else {
                g_byte_array_append (raw_all, raw->data, raw->len);
                g_byte_array_unref (raw);
            }
        }

        if (!raw_all) {
            offset = 0;
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
        } else {
            guint32 offset_offset;

            /* Offset of the offset */
            offset_offset = builder->fixed_buffer->len;
            /* Length *not* in LE yet */
            offset = builder->variable_buffer->len;
            /* Add the offset value */
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
            /* Configure the value to get updated */
            g_array_append_val (builder->offsets, offset_offset);
            /* Add the final array itself */
            g_byte_array_append (builder->variable_buffer, raw_all->data, raw_all->len);
            g_byte_array_unref (raw_all);
        }
    } else {
        for (i = 0; i < n_values; i++) {
            guint32 length;
            guint32 offset_offset;
            GByteArray *raw;

            raw = _mbim_ipv6_element_struct_new (values[i]);
            g_assert (raw->len > 0);

            /* Offset of the offset */
            offset_offset = builder->fixed_buffer->len;

            /* Length *not* in LE yet */
            offset = builder->variable_buffer->len;
            /* Add the offset value */
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
            /* Configure the value to get updated */
            g_array_append_val (builder->offsets, offset_offset);

            /* Add the length value */
            length = GUINT32_TO_LE (raw->len);
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&length, sizeof (length));

            /* And finally, the bytearray itself to the variable buffer */
            g_byte_array_append (builder->variable_buffer, (const guint8 *)raw->data, (guint)raw->len);
            g_byte_array_unref (raw);
        }
    }
}

static void
_mbim_message_command_builder_append_mbim_ipv6_element_struct_array (
    MbimMessageCommandBuilder *builder,
    const MbimIPv6Element *const *values,
    guint32 n_values,
    gboolean refs)
{
    _mbim_struct_builder_append_mbim_ipv6_element_struct_array (builder->contents_builder, values, n_values, refs);
}

/*****************************************************************************/
/* Struct: MbimDeviceServiceElement */

static void
_mbim_device_service_element_free (MbimDeviceServiceElement *var)
{
    if (!var)
        return;

    g_free (var->cids);
    g_free (var);
}

void
mbim_device_service_element_array_free (MbimDeviceServiceElementArray *array)
{
    guint32 i;

    if (!array)
        return;

    for (i = 0; array[i]; i++)
        _mbim_device_service_element_free (array[i]);
    g_free (array);
}

static MbimDeviceServiceElement *
_mbim_message_read_mbim_device_service_element_struct (
    const MbimMessage *self,
    guint32 relative_offset,
    guint32 *bytes_read,
    GError **error)
{
    gboolean success = FALSE;
    MbimDeviceServiceElement *out;
    guint32 offset = relative_offset;

    g_assert (self != NULL);

    out = g_new0 (MbimDeviceServiceElement, 1);

    {
        const MbimUuid *tmp;

        if (!_mbim_message_read_uuid (self, offset, &tmp, error))
            goto out;
        memcpy (&(out->device_service_id), tmp, 16);
        offset += 16;
    }

    if (!_mbim_message_read_guint32 (self, offset, &out->dss_payload, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->max_dss_instances, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->cids_count, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32_array (self, out->cids_count, offset, &out->cids, error))
        goto out;
    offset += (4 * out->cids_count);

    success = TRUE;

 out:
    if (success) {
        if (bytes_read)
            *bytes_read = (offset - relative_offset);
        return out;
    }

    g_free (out);
    return NULL;
}

static gboolean
_mbim_message_read_mbim_device_service_element_struct_array (
    const MbimMessage *self,
    guint32 array_size,
    guint32 relative_offset_array_start,
    gboolean refs,
    MbimDeviceServiceElementArray **out_array,
    GError **error)
{
    GError *inner_error = NULL;
    MbimDeviceServiceElementArray *out;
    guint32 i;
    guint32 offset;

    if (!array_size) {
        *out_array = NULL;
        return TRUE;
    }

    out = g_new0 (MbimDeviceServiceElement *, array_size + 1);

    if (!refs) {
        _mbim_message_read_guint32 (self, relative_offset_array_start, &offset, &inner_error);
        for (i = 0; !inner_error && (i < array_size); i++, offset += 0)
            out[i] = _mbim_message_read_mbim_device_service_element_struct (self, offset, NULL, &inner_error);
    } else {
        offset = relative_offset_array_start;
        for (i = 0; !inner_error && (i < array_size); i++, offset += 8) {
            guint32 tmp_offset;

            if (_mbim_message_read_guint32 (self, offset, &tmp_offset, &inner_error))
                out[i] = _mbim_message_read_mbim_device_service_element_struct (self, tmp_offset, NULL, &inner_error);
        }
    }

    if (!inner_error) {
        *out_array = out;
        return TRUE;
    }

    mbim_device_service_element_array_free (out);
    g_propagate_error (error, inner_error);
    return FALSE;
}

static gchar *
_mbim_message_print_mbim_device_service_element_struct (
    const MbimDeviceServiceElement *self,
    const gchar *line_prefix)
{
    GString *str;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  DeviceServiceId = ", line_prefix);
    {
        gchar *tmpstr;

        tmpstr = mbim_uuid_get_printable (&(self->device_service_id));
        g_string_append_printf (str, "'%s'", tmpstr);
        g_free (tmpstr);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  DssPayload = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->dss_payload);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  MaxDssInstances = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->max_dss_instances);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  CidsCount = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->cids_count);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Cids = ", line_prefix);
    {
        guint i;

        g_string_append (str, "'");
        for (i = 0; i < self->cids_count; i++)
            g_string_append_printf (str, "%" G_GUINT32_FORMAT "%s", self->cids[i], (i == (self->cids_count - 1)) ? "" : "," );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");
    return g_string_free (str, FALSE);
}

static GByteArray *
_mbim_device_service_element_struct_new (const MbimDeviceServiceElement *value)
{
    MbimStructBuilder *builder;

    g_assert (value != NULL);

    builder = _mbim_struct_builder_new ();
    _mbim_struct_builder_append_uuid (builder, &(value->device_service_id));
    _mbim_struct_builder_append_guint32 (builder, value->dss_payload);
    _mbim_struct_builder_append_guint32 (builder, value->max_dss_instances);
    _mbim_struct_builder_append_guint32 (builder, value->cids_count);
    _mbim_struct_builder_append_guint32_array (builder, value->cids, value->cids_count);

    return _mbim_struct_builder_complete (builder);
}

static void
_mbim_struct_builder_append_mbim_device_service_element_struct (
    MbimStructBuilder *builder,
    const MbimDeviceServiceElement *value)
{
    GByteArray *raw;

    raw = _mbim_device_service_element_struct_new (value);
    g_byte_array_append (builder->fixed_buffer, raw->data, raw->len);
    g_byte_array_unref (raw);
}

static void
_mbim_message_command_builder_append_mbim_device_service_element_struct (
    MbimMessageCommandBuilder *builder,
    const MbimDeviceServiceElement *value)
{
    _mbim_struct_builder_append_mbim_device_service_element_struct (builder->contents_builder, value);
}

static void
_mbim_struct_builder_append_mbim_device_service_element_struct_array (
    MbimStructBuilder *builder,
    const MbimDeviceServiceElement *const *values,
    guint32 n_values,
    gboolean refs)
{
    guint32 offset;
    guint32 i;
    GByteArray *raw_all = NULL;

    if (!refs) {
        for (i = 0; i < n_values; i++) {
            GByteArray *raw;

            raw = _mbim_device_service_element_struct_new (values[i]);
            if (!raw_all)
                raw_all = raw;
            else {
                g_byte_array_append (raw_all, raw->data, raw->len);
                g_byte_array_unref (raw);
            }
        }

        if (!raw_all) {
            offset = 0;
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
        } else {
            guint32 offset_offset;

            /* Offset of the offset */
            offset_offset = builder->fixed_buffer->len;
            /* Length *not* in LE yet */
            offset = builder->variable_buffer->len;
            /* Add the offset value */
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
            /* Configure the value to get updated */
            g_array_append_val (builder->offsets, offset_offset);
            /* Add the final array itself */
            g_byte_array_append (builder->variable_buffer, raw_all->data, raw_all->len);
            g_byte_array_unref (raw_all);
        }
    } else {
        for (i = 0; i < n_values; i++) {
            guint32 length;
            guint32 offset_offset;
            GByteArray *raw;

            raw = _mbim_device_service_element_struct_new (values[i]);
            g_assert (raw->len > 0);

            /* Offset of the offset */
            offset_offset = builder->fixed_buffer->len;

            /* Length *not* in LE yet */
            offset = builder->variable_buffer->len;
            /* Add the offset value */
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
            /* Configure the value to get updated */
            g_array_append_val (builder->offsets, offset_offset);

            /* Add the length value */
            length = GUINT32_TO_LE (raw->len);
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&length, sizeof (length));

            /* And finally, the bytearray itself to the variable buffer */
            g_byte_array_append (builder->variable_buffer, (const guint8 *)raw->data, (guint)raw->len);
            g_byte_array_unref (raw);
        }
    }
}

static void
_mbim_message_command_builder_append_mbim_device_service_element_struct_array (
    MbimMessageCommandBuilder *builder,
    const MbimDeviceServiceElement *const *values,
    guint32 n_values,
    gboolean refs)
{
    _mbim_struct_builder_append_mbim_device_service_element_struct_array (builder->contents_builder, values, n_values, refs);
}

/*****************************************************************************/
/* Struct: MbimEventEntry */

static void
_mbim_event_entry_free (MbimEventEntry *var)
{
    if (!var)
        return;

    g_free (var->cids);
    g_free (var);
}

void
mbim_event_entry_array_free (MbimEventEntryArray *array)
{
    guint32 i;

    if (!array)
        return;

    for (i = 0; array[i]; i++)
        _mbim_event_entry_free (array[i]);
    g_free (array);
}

static MbimEventEntry *
_mbim_message_read_mbim_event_entry_struct (
    const MbimMessage *self,
    guint32 relative_offset,
    guint32 *bytes_read,
    GError **error)
{
    gboolean success = FALSE;
    MbimEventEntry *out;
    guint32 offset = relative_offset;

    g_assert (self != NULL);

    out = g_new0 (MbimEventEntry, 1);

    {
        const MbimUuid *tmp;

        if (!_mbim_message_read_uuid (self, offset, &tmp, error))
            goto out;
        memcpy (&(out->device_service_id), tmp, 16);
        offset += 16;
    }

    if (!_mbim_message_read_guint32 (self, offset, &out->cids_count, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32_array (self, out->cids_count, offset, &out->cids, error))
        goto out;
    offset += (4 * out->cids_count);

    success = TRUE;

 out:
    if (success) {
        if (bytes_read)
            *bytes_read = (offset - relative_offset);
        return out;
    }

    g_free (out);
    return NULL;
}

static gboolean
_mbim_message_read_mbim_event_entry_struct_array (
    const MbimMessage *self,
    guint32 array_size,
    guint32 relative_offset_array_start,
    gboolean refs,
    MbimEventEntryArray **out_array,
    GError **error)
{
    GError *inner_error = NULL;
    MbimEventEntryArray *out;
    guint32 i;
    guint32 offset;

    if (!array_size) {
        *out_array = NULL;
        return TRUE;
    }

    out = g_new0 (MbimEventEntry *, array_size + 1);

    if (!refs) {
        _mbim_message_read_guint32 (self, relative_offset_array_start, &offset, &inner_error);
        for (i = 0; !inner_error && (i < array_size); i++, offset += 0)
            out[i] = _mbim_message_read_mbim_event_entry_struct (self, offset, NULL, &inner_error);
    } else {
        offset = relative_offset_array_start;
        for (i = 0; !inner_error && (i < array_size); i++, offset += 8) {
            guint32 tmp_offset;

            if (_mbim_message_read_guint32 (self, offset, &tmp_offset, &inner_error))
                out[i] = _mbim_message_read_mbim_event_entry_struct (self, tmp_offset, NULL, &inner_error);
        }
    }

    if (!inner_error) {
        *out_array = out;
        return TRUE;
    }

    mbim_event_entry_array_free (out);
    g_propagate_error (error, inner_error);
    return FALSE;
}

static gchar *
_mbim_message_print_mbim_event_entry_struct (
    const MbimEventEntry *self,
    const gchar *line_prefix)
{
    GString *str;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  DeviceServiceId = ", line_prefix);
    {
        gchar *tmpstr;

        tmpstr = mbim_uuid_get_printable (&(self->device_service_id));
        g_string_append_printf (str, "'%s'", tmpstr);
        g_free (tmpstr);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  CidsCount = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->cids_count);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Cids = ", line_prefix);
    {
        guint i;

        g_string_append (str, "'");
        for (i = 0; i < self->cids_count; i++)
            g_string_append_printf (str, "%" G_GUINT32_FORMAT "%s", self->cids[i], (i == (self->cids_count - 1)) ? "" : "," );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");
    return g_string_free (str, FALSE);
}

static GByteArray *
_mbim_event_entry_struct_new (const MbimEventEntry *value)
{
    MbimStructBuilder *builder;

    g_assert (value != NULL);

    builder = _mbim_struct_builder_new ();
    _mbim_struct_builder_append_uuid (builder, &(value->device_service_id));
    _mbim_struct_builder_append_guint32 (builder, value->cids_count);
    _mbim_struct_builder_append_guint32_array (builder, value->cids, value->cids_count);

    return _mbim_struct_builder_complete (builder);
}

static void
_mbim_struct_builder_append_mbim_event_entry_struct (
    MbimStructBuilder *builder,
    const MbimEventEntry *value)
{
    GByteArray *raw;

    raw = _mbim_event_entry_struct_new (value);
    g_byte_array_append (builder->fixed_buffer, raw->data, raw->len);
    g_byte_array_unref (raw);
}

static void
_mbim_message_command_builder_append_mbim_event_entry_struct (
    MbimMessageCommandBuilder *builder,
    const MbimEventEntry *value)
{
    _mbim_struct_builder_append_mbim_event_entry_struct (builder->contents_builder, value);
}

static void
_mbim_struct_builder_append_mbim_event_entry_struct_array (
    MbimStructBuilder *builder,
    const MbimEventEntry *const *values,
    guint32 n_values,
    gboolean refs)
{
    guint32 offset;
    guint32 i;
    GByteArray *raw_all = NULL;

    if (!refs) {
        for (i = 0; i < n_values; i++) {
            GByteArray *raw;

            raw = _mbim_event_entry_struct_new (values[i]);
            if (!raw_all)
                raw_all = raw;
            else {
                g_byte_array_append (raw_all, raw->data, raw->len);
                g_byte_array_unref (raw);
            }
        }

        if (!raw_all) {
            offset = 0;
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
        } else {
            guint32 offset_offset;

            /* Offset of the offset */
            offset_offset = builder->fixed_buffer->len;
            /* Length *not* in LE yet */
            offset = builder->variable_buffer->len;
            /* Add the offset value */
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
            /* Configure the value to get updated */
            g_array_append_val (builder->offsets, offset_offset);
            /* Add the final array itself */
            g_byte_array_append (builder->variable_buffer, raw_all->data, raw_all->len);
            g_byte_array_unref (raw_all);
        }
    } else {
        for (i = 0; i < n_values; i++) {
            guint32 length;
            guint32 offset_offset;
            GByteArray *raw;

            raw = _mbim_event_entry_struct_new (values[i]);
            g_assert (raw->len > 0);

            /* Offset of the offset */
            offset_offset = builder->fixed_buffer->len;

            /* Length *not* in LE yet */
            offset = builder->variable_buffer->len;
            /* Add the offset value */
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
            /* Configure the value to get updated */
            g_array_append_val (builder->offsets, offset_offset);

            /* Add the length value */
            length = GUINT32_TO_LE (raw->len);
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&length, sizeof (length));

            /* And finally, the bytearray itself to the variable buffer */
            g_byte_array_append (builder->variable_buffer, (const guint8 *)raw->data, (guint)raw->len);
            g_byte_array_unref (raw);
        }
    }
}

static void
_mbim_message_command_builder_append_mbim_event_entry_struct_array (
    MbimMessageCommandBuilder *builder,
    const MbimEventEntry *const *values,
    guint32 n_values,
    gboolean refs)
{
    _mbim_struct_builder_append_mbim_event_entry_struct_array (builder->contents_builder, values, n_values, refs);
}

/*****************************************************************************/
/* Struct: MbimPacketFilter */

static void
_mbim_packet_filter_free (MbimPacketFilter *var)
{
    if (!var)
        return;

    g_free (var->packet_filter);
    g_free (var->packet_mask);
    g_free (var);
}

void
mbim_packet_filter_array_free (MbimPacketFilterArray *array)
{
    guint32 i;

    if (!array)
        return;

    for (i = 0; array[i]; i++)
        _mbim_packet_filter_free (array[i]);
    g_free (array);
}

static MbimPacketFilter *
_mbim_message_read_mbim_packet_filter_struct (
    const MbimMessage *self,
    guint32 relative_offset,
    guint32 *bytes_read,
    GError **error)
{
    gboolean success = FALSE;
    MbimPacketFilter *out;
    guint32 offset = relative_offset;

    g_assert (self != NULL);

    out = g_new0 (MbimPacketFilter, 1);

    if (!_mbim_message_read_guint32 (self, offset, &out->filter_size, error))
        goto out;
    offset += 4;

    {
        const guint8 *tmp;

        if (!_mbim_message_read_byte_array (self, relative_offset, offset, TRUE, FALSE, out->filter_size, &tmp, NULL, error))
            goto out;
        out->packet_filter = g_malloc (out->filter_size);
        memcpy (out->packet_filter, tmp, out->filter_size);
        offset += 4;
    }

    {
        const guint8 *tmp;

        if (!_mbim_message_read_byte_array (self, relative_offset, offset, TRUE, FALSE, out->filter_size, &tmp, NULL, error))
            goto out;
        out->packet_mask = g_malloc (out->filter_size);
        memcpy (out->packet_mask, tmp, out->filter_size);
        offset += 4;
    }

    success = TRUE;

 out:
    if (success) {
        if (bytes_read)
            *bytes_read = (offset - relative_offset);
        return out;
    }

    g_free (out->packet_filter);
    g_free (out->packet_mask);
    g_free (out);
    return NULL;
}

static gboolean
_mbim_message_read_mbim_packet_filter_struct_array (
    const MbimMessage *self,
    guint32 array_size,
    guint32 relative_offset_array_start,
    gboolean refs,
    MbimPacketFilterArray **out_array,
    GError **error)
{
    GError *inner_error = NULL;
    MbimPacketFilterArray *out;
    guint32 i;
    guint32 offset;

    if (!array_size) {
        *out_array = NULL;
        return TRUE;
    }

    out = g_new0 (MbimPacketFilter *, array_size + 1);

    if (!refs) {
        _mbim_message_read_guint32 (self, relative_offset_array_start, &offset, &inner_error);
        for (i = 0; !inner_error && (i < array_size); i++, offset += 0)
            out[i] = _mbim_message_read_mbim_packet_filter_struct (self, offset, NULL, &inner_error);
    } else {
        offset = relative_offset_array_start;
        for (i = 0; !inner_error && (i < array_size); i++, offset += 8) {
            guint32 tmp_offset;

            if (_mbim_message_read_guint32 (self, offset, &tmp_offset, &inner_error))
                out[i] = _mbim_message_read_mbim_packet_filter_struct (self, tmp_offset, NULL, &inner_error);
        }
    }

    if (!inner_error) {
        *out_array = out;
        return TRUE;
    }

    mbim_packet_filter_array_free (out);
    g_propagate_error (error, inner_error);
    return FALSE;
}

static gchar *
_mbim_message_print_mbim_packet_filter_struct (
    const MbimPacketFilter *self,
    const gchar *line_prefix)
{
    GString *str;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  FilterSize = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->filter_size);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  PacketFilter = ", line_prefix);
    {
        guint i;
        guint array_size;

        array_size = self->filter_size;
        g_string_append (str, "'");
        for (i = 0; i < array_size; i++)
            g_string_append_printf (str, "%02x%s", self->packet_filter[i], (i == (array_size - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  PacketMask = ", line_prefix);
    {
        guint i;
        guint array_size;

        array_size = self->filter_size;
        g_string_append (str, "'");
        for (i = 0; i < array_size; i++)
            g_string_append_printf (str, "%02x%s", self->packet_mask[i], (i == (array_size - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");
    return g_string_free (str, FALSE);
}

static GByteArray *
_mbim_packet_filter_struct_new (const MbimPacketFilter *value)
{
    MbimStructBuilder *builder;

    g_assert (value != NULL);

    builder = _mbim_struct_builder_new ();
    _mbim_struct_builder_append_guint32 (builder, value->filter_size);
    _mbim_struct_builder_append_byte_array (builder, TRUE, FALSE, TRUE, value->packet_filter, value->filter_size);
    _mbim_struct_builder_append_byte_array (builder, TRUE, FALSE, TRUE, value->packet_mask, value->filter_size);

    return _mbim_struct_builder_complete (builder);
}

static void
_mbim_struct_builder_append_mbim_packet_filter_struct (
    MbimStructBuilder *builder,
    const MbimPacketFilter *value)
{
    GByteArray *raw;

    raw = _mbim_packet_filter_struct_new (value);
    g_byte_array_append (builder->fixed_buffer, raw->data, raw->len);
    g_byte_array_unref (raw);
}

static void
_mbim_message_command_builder_append_mbim_packet_filter_struct (
    MbimMessageCommandBuilder *builder,
    const MbimPacketFilter *value)
{
    _mbim_struct_builder_append_mbim_packet_filter_struct (builder->contents_builder, value);
}

static void
_mbim_struct_builder_append_mbim_packet_filter_struct_array (
    MbimStructBuilder *builder,
    const MbimPacketFilter *const *values,
    guint32 n_values,
    gboolean refs)
{
    guint32 offset;
    guint32 i;
    GByteArray *raw_all = NULL;

    if (!refs) {
        for (i = 0; i < n_values; i++) {
            GByteArray *raw;

            raw = _mbim_packet_filter_struct_new (values[i]);
            if (!raw_all)
                raw_all = raw;
            else {
                g_byte_array_append (raw_all, raw->data, raw->len);
                g_byte_array_unref (raw);
            }
        }

        if (!raw_all) {
            offset = 0;
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
        } else {
            guint32 offset_offset;

            /* Offset of the offset */
            offset_offset = builder->fixed_buffer->len;
            /* Length *not* in LE yet */
            offset = builder->variable_buffer->len;
            /* Add the offset value */
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
            /* Configure the value to get updated */
            g_array_append_val (builder->offsets, offset_offset);
            /* Add the final array itself */
            g_byte_array_append (builder->variable_buffer, raw_all->data, raw_all->len);
            g_byte_array_unref (raw_all);
        }
    } else {
        for (i = 0; i < n_values; i++) {
            guint32 length;
            guint32 offset_offset;
            GByteArray *raw;

            raw = _mbim_packet_filter_struct_new (values[i]);
            g_assert (raw->len > 0);

            /* Offset of the offset */
            offset_offset = builder->fixed_buffer->len;

            /* Length *not* in LE yet */
            offset = builder->variable_buffer->len;
            /* Add the offset value */
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
            /* Configure the value to get updated */
            g_array_append_val (builder->offsets, offset_offset);

            /* Add the length value */
            length = GUINT32_TO_LE (raw->len);
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&length, sizeof (length));

            /* And finally, the bytearray itself to the variable buffer */
            g_byte_array_append (builder->variable_buffer, (const guint8 *)raw->data, (guint)raw->len);
            g_byte_array_unref (raw);
        }
    }
}

static void
_mbim_message_command_builder_append_mbim_packet_filter_struct_array (
    MbimMessageCommandBuilder *builder,
    const MbimPacketFilter *const *values,
    guint32 n_values,
    gboolean refs)
{
    _mbim_struct_builder_append_mbim_packet_filter_struct_array (builder->contents_builder, values, n_values, refs);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Device Caps */

MbimMessage *
mbim_message_device_caps_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_DEVICE_CAPS,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_device_caps_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Device Caps */

gboolean
mbim_message_device_caps_response_parse (
    const MbimMessage *message,
    MbimDeviceType *out_device_type,
    MbimCellularClass *out_cellular_class,
    MbimVoiceClass *out_voice_class,
    MbimSimClass *out_sim_class,
    MbimDataClass *out_data_class,
    MbimSmsCaps *out_sms_caps,
    MbimCtrlCaps *out_control_caps,
    guint32 *out_max_sessions,
    gchar **out_custom_data_class,
    gchar **out_device_id,
    gchar **out_firmware_info,
    gchar **out_hardware_info,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    gchar *_custom_data_class = NULL;
    gchar *_device_id = NULL;
    gchar *_firmware_info = NULL;
    gchar *_hardware_info = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'DeviceType' variable */
    {
        if (out_device_type != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_device_type = (MbimDeviceType)aux;
        }
        offset += 4;
    }

    /* Read the 'CellularClass' variable */
    {
        if (out_cellular_class != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_cellular_class = (MbimCellularClass)aux;
        }
        offset += 4;
    }

    /* Read the 'VoiceClass' variable */
    {
        if (out_voice_class != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_voice_class = (MbimVoiceClass)aux;
        }
        offset += 4;
    }

    /* Read the 'SimClass' variable */
    {
        if (out_sim_class != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_sim_class = (MbimSimClass)aux;
        }
        offset += 4;
    }

    /* Read the 'DataClass' variable */
    {
        if (out_data_class != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_data_class = (MbimDataClass)aux;
        }
        offset += 4;
    }

    /* Read the 'SmsCaps' variable */
    {
        if (out_sms_caps != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_sms_caps = (MbimSmsCaps)aux;
        }
        offset += 4;
    }

    /* Read the 'ControlCaps' variable */
    {
        if (out_control_caps != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_control_caps = (MbimCtrlCaps)aux;
        }
        offset += 4;
    }

    /* Read the 'MaxSessions' variable */
    {
        if ((out_max_sessions != NULL) && !_mbim_message_read_guint32 (message, offset, out_max_sessions, error))
            goto out;
        offset += 4;
    }

    /* Read the 'CustomDataClass' variable */
    {
        if ((out_custom_data_class != NULL) && !_mbim_message_read_string (message, 0, offset, &_custom_data_class, error))
            goto out;
        offset += 8;
    }

    /* Read the 'DeviceId' variable */
    {
        if ((out_device_id != NULL) && !_mbim_message_read_string (message, 0, offset, &_device_id, error))
            goto out;
        offset += 8;
    }

    /* Read the 'FirmwareInfo' variable */
    {
        if ((out_firmware_info != NULL) && !_mbim_message_read_string (message, 0, offset, &_firmware_info, error))
            goto out;
        offset += 8;
    }

    /* Read the 'HardwareInfo' variable */
    {
        if ((out_hardware_info != NULL) && !_mbim_message_read_string (message, 0, offset, &_hardware_info, error))
            goto out;
        offset += 8;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_custom_data_class != NULL)
            *out_custom_data_class = _custom_data_class;
        if (out_device_id != NULL)
            *out_device_id = _device_id;
        if (out_firmware_info != NULL)
            *out_firmware_info = _firmware_info;
        if (out_hardware_info != NULL)
            *out_hardware_info = _hardware_info;
    } else {
        g_free (_custom_data_class);
        g_free (_device_id);
        g_free (_firmware_info);
        g_free (_hardware_info);
    }

    return success;
}

static gchar *
mbim_message_device_caps_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  DeviceType = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_DEVICE_TYPE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_device_type_get_string ((MbimDeviceType)tmp));
#elif defined __MBIM_DEVICE_TYPE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_device_type_build_string_from_mask ((MbimDeviceType)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  CellularClass = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_CELLULAR_CLASS_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_cellular_class_get_string ((MbimCellularClass)tmp));
#elif defined __MBIM_CELLULAR_CLASS_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_cellular_class_build_string_from_mask ((MbimCellularClass)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  VoiceClass = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_VOICE_CLASS_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_voice_class_get_string ((MbimVoiceClass)tmp));
#elif defined __MBIM_VOICE_CLASS_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_voice_class_build_string_from_mask ((MbimVoiceClass)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  SimClass = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_SIM_CLASS_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_sim_class_get_string ((MbimSimClass)tmp));
#elif defined __MBIM_SIM_CLASS_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_sim_class_build_string_from_mask ((MbimSimClass)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  DataClass = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_DATA_CLASS_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_data_class_get_string ((MbimDataClass)tmp));
#elif defined __MBIM_DATA_CLASS_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_data_class_build_string_from_mask ((MbimDataClass)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  SmsCaps = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_SMS_CAPS_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_sms_caps_get_string ((MbimSmsCaps)tmp));
#elif defined __MBIM_SMS_CAPS_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_sms_caps_build_string_from_mask ((MbimSmsCaps)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ControlCaps = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_CTRL_CAPS_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_ctrl_caps_get_string ((MbimCtrlCaps)tmp));
#elif defined __MBIM_CTRL_CAPS_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_ctrl_caps_build_string_from_mask ((MbimCtrlCaps)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  MaxSessions = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  CustomDataClass = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  DeviceId = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  FirmwareInfo = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  HardwareInfo = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Subscriber Ready Status */

MbimMessage *
mbim_message_subscriber_ready_status_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_SUBSCRIBER_READY_STATUS,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_subscriber_ready_status_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Subscriber Ready Status */

gboolean
mbim_message_subscriber_ready_status_response_parse (
    const MbimMessage *message,
    MbimSubscriberReadyState *out_ready_state,
    gchar **out_subscriber_id,
    gchar **out_sim_icc_id,
    MbimReadyInfoFlag *out_ready_info,
    guint32 *out_telephone_numbers_count,
    gchar ***out_telephone_numbers,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    gchar *_subscriber_id = NULL;
    gchar *_sim_icc_id = NULL;
    guint32 _telephone_numbers_count;
    gchar **_telephone_numbers = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'ReadyState' variable */
    {
        if (out_ready_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_ready_state = (MbimSubscriberReadyState)aux;
        }
        offset += 4;
    }

    /* Read the 'SubscriberId' variable */
    {
        if ((out_subscriber_id != NULL) && !_mbim_message_read_string (message, 0, offset, &_subscriber_id, error))
            goto out;
        offset += 8;
    }

    /* Read the 'SimIccId' variable */
    {
        if ((out_sim_icc_id != NULL) && !_mbim_message_read_string (message, 0, offset, &_sim_icc_id, error))
            goto out;
        offset += 8;
    }

    /* Read the 'ReadyInfo' variable */
    {
        if (out_ready_info != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_ready_info = (MbimReadyInfoFlag)aux;
        }
        offset += 4;
    }

    /* Read the 'TelephoneNumbersCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_telephone_numbers_count, error))
            goto out;
        if (out_telephone_numbers_count != NULL)
            *out_telephone_numbers_count = _telephone_numbers_count;
        offset += 4;
    }

    /* Read the 'TelephoneNumbers' variable */
    {
        if ((out_telephone_numbers != NULL) && !_mbim_message_read_string_array (message, _telephone_numbers_count, 0, offset, &_telephone_numbers, error))
            goto out;
        offset += (8 * _telephone_numbers_count);
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_subscriber_id != NULL)
            *out_subscriber_id = _subscriber_id;
        if (out_sim_icc_id != NULL)
            *out_sim_icc_id = _sim_icc_id;
        if (out_telephone_numbers != NULL)
            *out_telephone_numbers = _telephone_numbers;
    } else {
        g_free (_subscriber_id);
        g_free (_sim_icc_id);
        g_strfreev (_telephone_numbers);
    }

    return success;
}

static gchar *
mbim_message_subscriber_ready_status_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _telephone_numbers_count;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ReadyState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_SUBSCRIBER_READY_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_subscriber_ready_state_get_string ((MbimSubscriberReadyState)tmp));
#elif defined __MBIM_SUBSCRIBER_READY_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_subscriber_ready_state_build_string_from_mask ((MbimSubscriberReadyState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  SubscriberId = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  SimIccId = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ReadyInfo = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_READY_INFO_FLAG_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_ready_info_flag_get_string ((MbimReadyInfoFlag)tmp));
#elif defined __MBIM_READY_INFO_FLAG_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_ready_info_flag_build_string_from_mask ((MbimReadyInfoFlag)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  TelephoneNumbersCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_telephone_numbers_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _telephone_numbers_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  TelephoneNumbers = ", line_prefix);
    {
        g_auto(GStrv) tmp = NULL;
        guint i;

        if (!_mbim_message_read_string_array (message, _telephone_numbers_count, 0, offset, &tmp, &inner_error))
            goto out;
        offset += (8 * _telephone_numbers_count);

        g_string_append (str, "'");
        for (i = 0; i < _telephone_numbers_count; i++) {
            g_string_append (str, tmp[i]);
            if (i < (_telephone_numbers_count - 1))
                g_string_append (str, ", ");
        }
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Notification): MBIM Message Subscriber Ready Status */

gboolean
mbim_message_subscriber_ready_status_notification_parse (
    const MbimMessage *message,
    MbimSubscriberReadyState *out_ready_state,
    gchar **out_subscriber_id,
    gchar **out_sim_icc_id,
    MbimReadyInfoFlag *out_ready_info,
    guint32 *out_telephone_numbers_count,
    gchar ***out_telephone_numbers,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    gchar *_subscriber_id = NULL;
    gchar *_sim_icc_id = NULL;
    guint32 _telephone_numbers_count;
    gchar **_telephone_numbers = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_INDICATE_STATUS) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a notification");
        return FALSE;
    }

    if (!mbim_message_indicate_status_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'ReadyState' variable */
    {
        if (out_ready_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_ready_state = (MbimSubscriberReadyState)aux;
        }
        offset += 4;
    }

    /* Read the 'SubscriberId' variable */
    {
        if ((out_subscriber_id != NULL) && !_mbim_message_read_string (message, 0, offset, &_subscriber_id, error))
            goto out;
        offset += 8;
    }

    /* Read the 'SimIccId' variable */
    {
        if ((out_sim_icc_id != NULL) && !_mbim_message_read_string (message, 0, offset, &_sim_icc_id, error))
            goto out;
        offset += 8;
    }

    /* Read the 'ReadyInfo' variable */
    {
        if (out_ready_info != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_ready_info = (MbimReadyInfoFlag)aux;
        }
        offset += 4;
    }

    /* Read the 'TelephoneNumbersCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_telephone_numbers_count, error))
            goto out;
        if (out_telephone_numbers_count != NULL)
            *out_telephone_numbers_count = _telephone_numbers_count;
        offset += 4;
    }

    /* Read the 'TelephoneNumbers' variable */
    {
        if ((out_telephone_numbers != NULL) && !_mbim_message_read_string_array (message, _telephone_numbers_count, 0, offset, &_telephone_numbers, error))
            goto out;
        offset += (8 * _telephone_numbers_count);
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_subscriber_id != NULL)
            *out_subscriber_id = _subscriber_id;
        if (out_sim_icc_id != NULL)
            *out_sim_icc_id = _sim_icc_id;
        if (out_telephone_numbers != NULL)
            *out_telephone_numbers = _telephone_numbers;
    } else {
        g_free (_subscriber_id);
        g_free (_sim_icc_id);
        g_strfreev (_telephone_numbers);
    }

    return success;
}

static gchar *
mbim_message_subscriber_ready_status_notification_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _telephone_numbers_count;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ReadyState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_SUBSCRIBER_READY_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_subscriber_ready_state_get_string ((MbimSubscriberReadyState)tmp));
#elif defined __MBIM_SUBSCRIBER_READY_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_subscriber_ready_state_build_string_from_mask ((MbimSubscriberReadyState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  SubscriberId = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  SimIccId = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ReadyInfo = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_READY_INFO_FLAG_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_ready_info_flag_get_string ((MbimReadyInfoFlag)tmp));
#elif defined __MBIM_READY_INFO_FLAG_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_ready_info_flag_build_string_from_mask ((MbimReadyInfoFlag)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  TelephoneNumbersCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_telephone_numbers_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _telephone_numbers_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  TelephoneNumbers = ", line_prefix);
    {
        g_auto(GStrv) tmp = NULL;
        guint i;

        if (!_mbim_message_read_string_array (message, _telephone_numbers_count, 0, offset, &tmp, &inner_error))
            goto out;
        offset += (8 * _telephone_numbers_count);

        g_string_append (str, "'");
        for (i = 0; i < _telephone_numbers_count; i++) {
            g_string_append (str, tmp[i]);
            if (i < (_telephone_numbers_count - 1))
                g_string_append (str, ", ");
        }
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Radio State */

MbimMessage *
mbim_message_radio_state_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_RADIO_STATE,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_radio_state_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message Radio State */

MbimMessage *
mbim_message_radio_state_set_new (
    MbimRadioSwitchState radio_state,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_RADIO_STATE,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, radio_state);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_radio_state_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  RadioState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_RADIO_SWITCH_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_radio_switch_state_get_string ((MbimRadioSwitchState)tmp));
#elif defined __MBIM_RADIO_SWITCH_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_radio_switch_state_build_string_from_mask ((MbimRadioSwitchState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Radio State */

gboolean
mbim_message_radio_state_response_parse (
    const MbimMessage *message,
    MbimRadioSwitchState *out_hw_radio_state,
    MbimRadioSwitchState *out_sw_radio_state,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'HwRadioState' variable */
    {
        if (out_hw_radio_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_hw_radio_state = (MbimRadioSwitchState)aux;
        }
        offset += 4;
    }

    /* Read the 'SwRadioState' variable */
    {
        if (out_sw_radio_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_sw_radio_state = (MbimRadioSwitchState)aux;
        }
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_radio_state_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  HwRadioState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_RADIO_SWITCH_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_radio_switch_state_get_string ((MbimRadioSwitchState)tmp));
#elif defined __MBIM_RADIO_SWITCH_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_radio_switch_state_build_string_from_mask ((MbimRadioSwitchState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  SwRadioState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_RADIO_SWITCH_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_radio_switch_state_get_string ((MbimRadioSwitchState)tmp));
#elif defined __MBIM_RADIO_SWITCH_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_radio_switch_state_build_string_from_mask ((MbimRadioSwitchState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Notification): MBIM Message Radio State */

gboolean
mbim_message_radio_state_notification_parse (
    const MbimMessage *message,
    MbimRadioSwitchState *out_hw_radio_state,
    MbimRadioSwitchState *out_sw_radio_state,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_INDICATE_STATUS) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a notification");
        return FALSE;
    }

    if (!mbim_message_indicate_status_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'HwRadioState' variable */
    {
        if (out_hw_radio_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_hw_radio_state = (MbimRadioSwitchState)aux;
        }
        offset += 4;
    }

    /* Read the 'SwRadioState' variable */
    {
        if (out_sw_radio_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_sw_radio_state = (MbimRadioSwitchState)aux;
        }
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_radio_state_notification_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  HwRadioState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_RADIO_SWITCH_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_radio_switch_state_get_string ((MbimRadioSwitchState)tmp));
#elif defined __MBIM_RADIO_SWITCH_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_radio_switch_state_build_string_from_mask ((MbimRadioSwitchState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  SwRadioState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_RADIO_SWITCH_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_radio_switch_state_get_string ((MbimRadioSwitchState)tmp));
#elif defined __MBIM_RADIO_SWITCH_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_radio_switch_state_build_string_from_mask ((MbimRadioSwitchState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Pin */

MbimMessage *
mbim_message_pin_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_PIN,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_pin_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message Pin */

MbimMessage *
mbim_message_pin_set_new (
    MbimPinType pin_type,
    MbimPinOperation pin_operation,
    const gchar *pin,
    const gchar *new_pin,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_PIN,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, pin_type);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, pin_operation);
    }
    {
        _mbim_message_command_builder_append_string (builder, pin);
    }
    {
        _mbim_message_command_builder_append_string (builder, new_pin);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_pin_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  PinType = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_PIN_TYPE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_pin_type_get_string ((MbimPinType)tmp));
#elif defined __MBIM_PIN_TYPE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_pin_type_build_string_from_mask ((MbimPinType)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PinOperation = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_PIN_OPERATION_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_pin_operation_get_string ((MbimPinOperation)tmp));
#elif defined __MBIM_PIN_OPERATION_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_pin_operation_build_string_from_mask ((MbimPinOperation)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Pin = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  NewPin = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Pin */

gboolean
mbim_message_pin_response_parse (
    const MbimMessage *message,
    MbimPinType *out_pin_type,
    MbimPinState *out_pin_state,
    guint32 *out_remaining_attempts,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'PinType' variable */
    {
        if (out_pin_type != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_pin_type = (MbimPinType)aux;
        }
        offset += 4;
    }

    /* Read the 'PinState' variable */
    {
        if (out_pin_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_pin_state = (MbimPinState)aux;
        }
        offset += 4;
    }

    /* Read the 'RemainingAttempts' variable */
    {
        if ((out_remaining_attempts != NULL) && !_mbim_message_read_guint32 (message, offset, out_remaining_attempts, error))
            goto out;
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_pin_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  PinType = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_PIN_TYPE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_pin_type_get_string ((MbimPinType)tmp));
#elif defined __MBIM_PIN_TYPE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_pin_type_build_string_from_mask ((MbimPinType)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PinState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_PIN_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_pin_state_get_string ((MbimPinState)tmp));
#elif defined __MBIM_PIN_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_pin_state_build_string_from_mask ((MbimPinState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  RemainingAttempts = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Pin List */

MbimMessage *
mbim_message_pin_list_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_PIN_LIST,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_pin_list_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Pin List */

gboolean
mbim_message_pin_list_response_parse (
    const MbimMessage *message,
    MbimPinDesc **out_pin_desc_pin1,
    MbimPinDesc **out_pin_desc_pin2,
    MbimPinDesc **out_pin_desc_device_sim_pin,
    MbimPinDesc **out_pin_desc_device_first_sim_pin,
    MbimPinDesc **out_pin_desc_network_pin,
    MbimPinDesc **out_pin_desc_network_subset_pin,
    MbimPinDesc **out_pin_desc_service_provider_pin,
    MbimPinDesc **out_pin_desc_corporate_pin,
    MbimPinDesc **out_pin_desc_subsidy_lock,
    MbimPinDesc **out_pin_desc_custom,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    MbimPinDesc *_pin_desc_pin1 = NULL;
    MbimPinDesc *_pin_desc_pin2 = NULL;
    MbimPinDesc *_pin_desc_device_sim_pin = NULL;
    MbimPinDesc *_pin_desc_device_first_sim_pin = NULL;
    MbimPinDesc *_pin_desc_network_pin = NULL;
    MbimPinDesc *_pin_desc_network_subset_pin = NULL;
    MbimPinDesc *_pin_desc_service_provider_pin = NULL;
    MbimPinDesc *_pin_desc_corporate_pin = NULL;
    MbimPinDesc *_pin_desc_subsidy_lock = NULL;
    MbimPinDesc *_pin_desc_custom = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'PinDescPin1' variable */
    {
        MbimPinDesc *tmp;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, error);
        if (!tmp)
            goto out;
        if (out_pin_desc_pin1 != NULL)
            _pin_desc_pin1 = tmp;
        else
             _mbim_pin_desc_free (tmp);
        offset += bytes_read;
    }

    /* Read the 'PinDescPin2' variable */
    {
        MbimPinDesc *tmp;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, error);
        if (!tmp)
            goto out;
        if (out_pin_desc_pin2 != NULL)
            _pin_desc_pin2 = tmp;
        else
             _mbim_pin_desc_free (tmp);
        offset += bytes_read;
    }

    /* Read the 'PinDescDeviceSimPin' variable */
    {
        MbimPinDesc *tmp;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, error);
        if (!tmp)
            goto out;
        if (out_pin_desc_device_sim_pin != NULL)
            _pin_desc_device_sim_pin = tmp;
        else
             _mbim_pin_desc_free (tmp);
        offset += bytes_read;
    }

    /* Read the 'PinDescDeviceFirstSimPin' variable */
    {
        MbimPinDesc *tmp;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, error);
        if (!tmp)
            goto out;
        if (out_pin_desc_device_first_sim_pin != NULL)
            _pin_desc_device_first_sim_pin = tmp;
        else
             _mbim_pin_desc_free (tmp);
        offset += bytes_read;
    }

    /* Read the 'PinDescNetworkPin' variable */
    {
        MbimPinDesc *tmp;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, error);
        if (!tmp)
            goto out;
        if (out_pin_desc_network_pin != NULL)
            _pin_desc_network_pin = tmp;
        else
             _mbim_pin_desc_free (tmp);
        offset += bytes_read;
    }

    /* Read the 'PinDescNetworkSubsetPin' variable */
    {
        MbimPinDesc *tmp;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, error);
        if (!tmp)
            goto out;
        if (out_pin_desc_network_subset_pin != NULL)
            _pin_desc_network_subset_pin = tmp;
        else
             _mbim_pin_desc_free (tmp);
        offset += bytes_read;
    }

    /* Read the 'PinDescServiceProviderPin' variable */
    {
        MbimPinDesc *tmp;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, error);
        if (!tmp)
            goto out;
        if (out_pin_desc_service_provider_pin != NULL)
            _pin_desc_service_provider_pin = tmp;
        else
             _mbim_pin_desc_free (tmp);
        offset += bytes_read;
    }

    /* Read the 'PinDescCorporatePin' variable */
    {
        MbimPinDesc *tmp;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, error);
        if (!tmp)
            goto out;
        if (out_pin_desc_corporate_pin != NULL)
            _pin_desc_corporate_pin = tmp;
        else
             _mbim_pin_desc_free (tmp);
        offset += bytes_read;
    }

    /* Read the 'PinDescSubsidyLock' variable */
    {
        MbimPinDesc *tmp;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, error);
        if (!tmp)
            goto out;
        if (out_pin_desc_subsidy_lock != NULL)
            _pin_desc_subsidy_lock = tmp;
        else
             _mbim_pin_desc_free (tmp);
        offset += bytes_read;
    }

    /* Read the 'PinDescCustom' variable */
    {
        MbimPinDesc *tmp;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, error);
        if (!tmp)
            goto out;
        if (out_pin_desc_custom != NULL)
            _pin_desc_custom = tmp;
        else
             _mbim_pin_desc_free (tmp);
        offset += bytes_read;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_pin_desc_pin1 != NULL)
            *out_pin_desc_pin1 = _pin_desc_pin1;
        if (out_pin_desc_pin2 != NULL)
            *out_pin_desc_pin2 = _pin_desc_pin2;
        if (out_pin_desc_device_sim_pin != NULL)
            *out_pin_desc_device_sim_pin = _pin_desc_device_sim_pin;
        if (out_pin_desc_device_first_sim_pin != NULL)
            *out_pin_desc_device_first_sim_pin = _pin_desc_device_first_sim_pin;
        if (out_pin_desc_network_pin != NULL)
            *out_pin_desc_network_pin = _pin_desc_network_pin;
        if (out_pin_desc_network_subset_pin != NULL)
            *out_pin_desc_network_subset_pin = _pin_desc_network_subset_pin;
        if (out_pin_desc_service_provider_pin != NULL)
            *out_pin_desc_service_provider_pin = _pin_desc_service_provider_pin;
        if (out_pin_desc_corporate_pin != NULL)
            *out_pin_desc_corporate_pin = _pin_desc_corporate_pin;
        if (out_pin_desc_subsidy_lock != NULL)
            *out_pin_desc_subsidy_lock = _pin_desc_subsidy_lock;
        if (out_pin_desc_custom != NULL)
            *out_pin_desc_custom = _pin_desc_custom;
    } else {
        mbim_pin_desc_free (_pin_desc_pin1);
        mbim_pin_desc_free (_pin_desc_pin2);
        mbim_pin_desc_free (_pin_desc_device_sim_pin);
        mbim_pin_desc_free (_pin_desc_device_first_sim_pin);
        mbim_pin_desc_free (_pin_desc_network_pin);
        mbim_pin_desc_free (_pin_desc_network_subset_pin);
        mbim_pin_desc_free (_pin_desc_service_provider_pin);
        mbim_pin_desc_free (_pin_desc_corporate_pin);
        mbim_pin_desc_free (_pin_desc_subsidy_lock);
        mbim_pin_desc_free (_pin_desc_custom);
    }

    return success;
}

static gchar *
mbim_message_pin_list_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  PinDescPin1 = ", line_prefix);
    {
        g_autoptr(MbimPinDesc) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_pin_desc_struct (tmp, new_line_prefix);
        g_string_append (str, struct_str);
        g_string_append_printf (str, "%s  }\n", line_prefix);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PinDescPin2 = ", line_prefix);
    {
        g_autoptr(MbimPinDesc) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_pin_desc_struct (tmp, new_line_prefix);
        g_string_append (str, struct_str);
        g_string_append_printf (str, "%s  }\n", line_prefix);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PinDescDeviceSimPin = ", line_prefix);
    {
        g_autoptr(MbimPinDesc) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_pin_desc_struct (tmp, new_line_prefix);
        g_string_append (str, struct_str);
        g_string_append_printf (str, "%s  }\n", line_prefix);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PinDescDeviceFirstSimPin = ", line_prefix);
    {
        g_autoptr(MbimPinDesc) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_pin_desc_struct (tmp, new_line_prefix);
        g_string_append (str, struct_str);
        g_string_append_printf (str, "%s  }\n", line_prefix);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PinDescNetworkPin = ", line_prefix);
    {
        g_autoptr(MbimPinDesc) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_pin_desc_struct (tmp, new_line_prefix);
        g_string_append (str, struct_str);
        g_string_append_printf (str, "%s  }\n", line_prefix);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PinDescNetworkSubsetPin = ", line_prefix);
    {
        g_autoptr(MbimPinDesc) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_pin_desc_struct (tmp, new_line_prefix);
        g_string_append (str, struct_str);
        g_string_append_printf (str, "%s  }\n", line_prefix);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PinDescServiceProviderPin = ", line_prefix);
    {
        g_autoptr(MbimPinDesc) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_pin_desc_struct (tmp, new_line_prefix);
        g_string_append (str, struct_str);
        g_string_append_printf (str, "%s  }\n", line_prefix);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PinDescCorporatePin = ", line_prefix);
    {
        g_autoptr(MbimPinDesc) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_pin_desc_struct (tmp, new_line_prefix);
        g_string_append (str, struct_str);
        g_string_append_printf (str, "%s  }\n", line_prefix);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PinDescSubsidyLock = ", line_prefix);
    {
        g_autoptr(MbimPinDesc) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_pin_desc_struct (tmp, new_line_prefix);
        g_string_append (str, struct_str);
        g_string_append_printf (str, "%s  }\n", line_prefix);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PinDescCustom = ", line_prefix);
    {
        g_autoptr(MbimPinDesc) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pin_desc_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_pin_desc_struct (tmp, new_line_prefix);
        g_string_append (str, struct_str);
        g_string_append_printf (str, "%s  }\n", line_prefix);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Home Provider */

MbimMessage *
mbim_message_home_provider_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_HOME_PROVIDER,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_home_provider_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message Home Provider */

MbimMessage *
mbim_message_home_provider_set_new (
    const MbimProvider *provider,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_HOME_PROVIDER,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_mbim_provider_struct (builder, provider);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_home_provider_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Provider = ", line_prefix);
    {
        g_autoptr(MbimProvider) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_provider_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_provider_struct (tmp, new_line_prefix);
        g_string_append (str, struct_str);
        g_string_append_printf (str, "%s  }\n", line_prefix);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Home Provider */

gboolean
mbim_message_home_provider_response_parse (
    const MbimMessage *message,
    MbimProvider **out_provider,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    MbimProvider *_provider = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'Provider' variable */
    {
        MbimProvider *tmp;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_provider_struct (message, offset, &bytes_read, error);
        if (!tmp)
            goto out;
        if (out_provider != NULL)
            _provider = tmp;
        else
             _mbim_provider_free (tmp);
        offset += bytes_read;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_provider != NULL)
            *out_provider = _provider;
    } else {
        mbim_provider_free (_provider);
    }

    return success;
}

static gchar *
mbim_message_home_provider_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Provider = ", line_prefix);
    {
        g_autoptr(MbimProvider) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_provider_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_provider_struct (tmp, new_line_prefix);
        g_string_append (str, struct_str);
        g_string_append_printf (str, "%s  }\n", line_prefix);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Preferred Providers */

MbimMessage *
mbim_message_preferred_providers_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_PREFERRED_PROVIDERS,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_preferred_providers_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message Preferred Providers */

MbimMessage *
mbim_message_preferred_providers_set_new (
    guint32 providers_count,
    const MbimProvider *const *providers,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_PREFERRED_PROVIDERS,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, providers_count);
    }
    {
        _mbim_message_command_builder_append_mbim_provider_struct_array (builder, providers, providers_count, TRUE);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_preferred_providers_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _providers_count;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ProvidersCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_providers_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _providers_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Providers = ", line_prefix);
    {
        g_autoptr(MbimProviderArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_provider_struct_array (message, _providers_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _providers_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _providers_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_provider_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Preferred Providers */

gboolean
mbim_message_preferred_providers_response_parse (
    const MbimMessage *message,
    guint32 *out_providers_count,
    MbimProviderArray **out_providers,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    guint32 _providers_count;
    MbimProvider **_providers = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'ProvidersCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_providers_count, error))
            goto out;
        if (out_providers_count != NULL)
            *out_providers_count = _providers_count;
        offset += 4;
    }

    /* Read the 'Providers' variable */
    {
        if ((out_providers != NULL) && !_mbim_message_read_mbim_provider_struct_array (message, _providers_count, offset, TRUE, &_providers, error))
            goto out;
        offset += (8 * _providers_count);
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_providers != NULL)
            *out_providers = _providers;
    } else {
        mbim_provider_array_free (_providers);
    }

    return success;
}

static gchar *
mbim_message_preferred_providers_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _providers_count;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ProvidersCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_providers_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _providers_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Providers = ", line_prefix);
    {
        g_autoptr(MbimProviderArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_provider_struct_array (message, _providers_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _providers_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _providers_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_provider_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Notification): MBIM Message Preferred Providers */

gboolean
mbim_message_preferred_providers_notification_parse (
    const MbimMessage *message,
    guint32 *out_providers_count,
    MbimProviderArray **out_providers,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    guint32 _providers_count;
    MbimProvider **_providers = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_INDICATE_STATUS) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a notification");
        return FALSE;
    }

    if (!mbim_message_indicate_status_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'ProvidersCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_providers_count, error))
            goto out;
        if (out_providers_count != NULL)
            *out_providers_count = _providers_count;
        offset += 4;
    }

    /* Read the 'Providers' variable */
    {
        if ((out_providers != NULL) && !_mbim_message_read_mbim_provider_struct_array (message, _providers_count, offset, TRUE, &_providers, error))
            goto out;
        offset += (8 * _providers_count);
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_providers != NULL)
            *out_providers = _providers;
    } else {
        mbim_provider_array_free (_providers);
    }

    return success;
}

static gchar *
mbim_message_preferred_providers_notification_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _providers_count;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ProvidersCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_providers_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _providers_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Providers = ", line_prefix);
    {
        g_autoptr(MbimProviderArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_provider_struct_array (message, _providers_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _providers_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _providers_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_provider_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Visible Providers */

MbimMessage *
mbim_message_visible_providers_query_new (
    MbimVisibleProvidersAction action,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_VISIBLE_PROVIDERS,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);
    {
        _mbim_message_command_builder_append_guint32 (builder, action);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_visible_providers_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Action = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_VISIBLE_PROVIDERS_ACTION_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_visible_providers_action_get_string ((MbimVisibleProvidersAction)tmp));
#elif defined __MBIM_VISIBLE_PROVIDERS_ACTION_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_visible_providers_action_build_string_from_mask ((MbimVisibleProvidersAction)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Visible Providers */

gboolean
mbim_message_visible_providers_response_parse (
    const MbimMessage *message,
    guint32 *out_providers_count,
    MbimProviderArray **out_providers,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    guint32 _providers_count;
    MbimProvider **_providers = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'ProvidersCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_providers_count, error))
            goto out;
        if (out_providers_count != NULL)
            *out_providers_count = _providers_count;
        offset += 4;
    }

    /* Read the 'Providers' variable */
    {
        if ((out_providers != NULL) && !_mbim_message_read_mbim_provider_struct_array (message, _providers_count, offset, TRUE, &_providers, error))
            goto out;
        offset += (8 * _providers_count);
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_providers != NULL)
            *out_providers = _providers;
    } else {
        mbim_provider_array_free (_providers);
    }

    return success;
}

static gchar *
mbim_message_visible_providers_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _providers_count;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ProvidersCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_providers_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _providers_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Providers = ", line_prefix);
    {
        g_autoptr(MbimProviderArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_provider_struct_array (message, _providers_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _providers_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _providers_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_provider_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Register State */

MbimMessage *
mbim_message_register_state_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_REGISTER_STATE,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_register_state_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message Register State */

MbimMessage *
mbim_message_register_state_set_new (
    const gchar *provider_id,
    MbimRegisterAction register_action,
    MbimDataClass data_class,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_REGISTER_STATE,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_string (builder, provider_id);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, register_action);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, data_class);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_register_state_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ProviderId = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  RegisterAction = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_REGISTER_ACTION_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_register_action_get_string ((MbimRegisterAction)tmp));
#elif defined __MBIM_REGISTER_ACTION_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_register_action_build_string_from_mask ((MbimRegisterAction)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  DataClass = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_DATA_CLASS_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_data_class_get_string ((MbimDataClass)tmp));
#elif defined __MBIM_DATA_CLASS_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_data_class_build_string_from_mask ((MbimDataClass)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Register State */

gboolean
mbim_message_register_state_response_parse (
    const MbimMessage *message,
    MbimNwError *out_nw_error,
    MbimRegisterState *out_register_state,
    MbimRegisterMode *out_register_mode,
    MbimDataClass *out_available_data_classes,
    MbimCellularClass *out_current_cellular_class,
    gchar **out_provider_id,
    gchar **out_provider_name,
    gchar **out_roaming_text,
    MbimRegistrationFlag *out_registration_flag,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    gchar *_provider_id = NULL;
    gchar *_provider_name = NULL;
    gchar *_roaming_text = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'NwError' variable */
    {
        if (out_nw_error != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_nw_error = (MbimNwError)aux;
        }
        offset += 4;
    }

    /* Read the 'RegisterState' variable */
    {
        if (out_register_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_register_state = (MbimRegisterState)aux;
        }
        offset += 4;
    }

    /* Read the 'RegisterMode' variable */
    {
        if (out_register_mode != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_register_mode = (MbimRegisterMode)aux;
        }
        offset += 4;
    }

    /* Read the 'AvailableDataClasses' variable */
    {
        if (out_available_data_classes != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_available_data_classes = (MbimDataClass)aux;
        }
        offset += 4;
    }

    /* Read the 'CurrentCellularClass' variable */
    {
        if (out_current_cellular_class != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_current_cellular_class = (MbimCellularClass)aux;
        }
        offset += 4;
    }

    /* Read the 'ProviderId' variable */
    {
        if ((out_provider_id != NULL) && !_mbim_message_read_string (message, 0, offset, &_provider_id, error))
            goto out;
        offset += 8;
    }

    /* Read the 'ProviderName' variable */
    {
        if ((out_provider_name != NULL) && !_mbim_message_read_string (message, 0, offset, &_provider_name, error))
            goto out;
        offset += 8;
    }

    /* Read the 'RoamingText' variable */
    {
        if ((out_roaming_text != NULL) && !_mbim_message_read_string (message, 0, offset, &_roaming_text, error))
            goto out;
        offset += 8;
    }

    /* Read the 'RegistrationFlag' variable */
    {
        if (out_registration_flag != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_registration_flag = (MbimRegistrationFlag)aux;
        }
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_provider_id != NULL)
            *out_provider_id = _provider_id;
        if (out_provider_name != NULL)
            *out_provider_name = _provider_name;
        if (out_roaming_text != NULL)
            *out_roaming_text = _roaming_text;
    } else {
        g_free (_provider_id);
        g_free (_provider_name);
        g_free (_roaming_text);
    }

    return success;
}

static gchar *
mbim_message_register_state_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  NwError = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_NW_ERROR_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_nw_error_get_string ((MbimNwError)tmp));
#elif defined __MBIM_NW_ERROR_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_nw_error_build_string_from_mask ((MbimNwError)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  RegisterState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_REGISTER_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_register_state_get_string ((MbimRegisterState)tmp));
#elif defined __MBIM_REGISTER_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_register_state_build_string_from_mask ((MbimRegisterState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  RegisterMode = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_REGISTER_MODE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_register_mode_get_string ((MbimRegisterMode)tmp));
#elif defined __MBIM_REGISTER_MODE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_register_mode_build_string_from_mask ((MbimRegisterMode)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  AvailableDataClasses = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_DATA_CLASS_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_data_class_get_string ((MbimDataClass)tmp));
#elif defined __MBIM_DATA_CLASS_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_data_class_build_string_from_mask ((MbimDataClass)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  CurrentCellularClass = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_CELLULAR_CLASS_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_cellular_class_get_string ((MbimCellularClass)tmp));
#elif defined __MBIM_CELLULAR_CLASS_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_cellular_class_build_string_from_mask ((MbimCellularClass)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ProviderId = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ProviderName = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  RoamingText = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  RegistrationFlag = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_REGISTRATION_FLAG_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_registration_flag_get_string ((MbimRegistrationFlag)tmp));
#elif defined __MBIM_REGISTRATION_FLAG_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_registration_flag_build_string_from_mask ((MbimRegistrationFlag)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Notification): MBIM Message Register State */

gboolean
mbim_message_register_state_notification_parse (
    const MbimMessage *message,
    MbimNwError *out_nw_error,
    MbimRegisterState *out_register_state,
    MbimRegisterMode *out_register_mode,
    MbimDataClass *out_available_data_classes,
    MbimCellularClass *out_current_cellular_class,
    gchar **out_provider_id,
    gchar **out_provider_name,
    gchar **out_roaming_text,
    MbimRegistrationFlag *out_registration_flag,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    gchar *_provider_id = NULL;
    gchar *_provider_name = NULL;
    gchar *_roaming_text = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_INDICATE_STATUS) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a notification");
        return FALSE;
    }

    if (!mbim_message_indicate_status_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'NwError' variable */
    {
        if (out_nw_error != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_nw_error = (MbimNwError)aux;
        }
        offset += 4;
    }

    /* Read the 'RegisterState' variable */
    {
        if (out_register_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_register_state = (MbimRegisterState)aux;
        }
        offset += 4;
    }

    /* Read the 'RegisterMode' variable */
    {
        if (out_register_mode != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_register_mode = (MbimRegisterMode)aux;
        }
        offset += 4;
    }

    /* Read the 'AvailableDataClasses' variable */
    {
        if (out_available_data_classes != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_available_data_classes = (MbimDataClass)aux;
        }
        offset += 4;
    }

    /* Read the 'CurrentCellularClass' variable */
    {
        if (out_current_cellular_class != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_current_cellular_class = (MbimCellularClass)aux;
        }
        offset += 4;
    }

    /* Read the 'ProviderId' variable */
    {
        if ((out_provider_id != NULL) && !_mbim_message_read_string (message, 0, offset, &_provider_id, error))
            goto out;
        offset += 8;
    }

    /* Read the 'ProviderName' variable */
    {
        if ((out_provider_name != NULL) && !_mbim_message_read_string (message, 0, offset, &_provider_name, error))
            goto out;
        offset += 8;
    }

    /* Read the 'RoamingText' variable */
    {
        if ((out_roaming_text != NULL) && !_mbim_message_read_string (message, 0, offset, &_roaming_text, error))
            goto out;
        offset += 8;
    }

    /* Read the 'RegistrationFlag' variable */
    {
        if (out_registration_flag != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_registration_flag = (MbimRegistrationFlag)aux;
        }
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_provider_id != NULL)
            *out_provider_id = _provider_id;
        if (out_provider_name != NULL)
            *out_provider_name = _provider_name;
        if (out_roaming_text != NULL)
            *out_roaming_text = _roaming_text;
    } else {
        g_free (_provider_id);
        g_free (_provider_name);
        g_free (_roaming_text);
    }

    return success;
}

static gchar *
mbim_message_register_state_notification_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  NwError = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_NW_ERROR_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_nw_error_get_string ((MbimNwError)tmp));
#elif defined __MBIM_NW_ERROR_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_nw_error_build_string_from_mask ((MbimNwError)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  RegisterState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_REGISTER_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_register_state_get_string ((MbimRegisterState)tmp));
#elif defined __MBIM_REGISTER_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_register_state_build_string_from_mask ((MbimRegisterState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  RegisterMode = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_REGISTER_MODE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_register_mode_get_string ((MbimRegisterMode)tmp));
#elif defined __MBIM_REGISTER_MODE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_register_mode_build_string_from_mask ((MbimRegisterMode)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  AvailableDataClasses = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_DATA_CLASS_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_data_class_get_string ((MbimDataClass)tmp));
#elif defined __MBIM_DATA_CLASS_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_data_class_build_string_from_mask ((MbimDataClass)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  CurrentCellularClass = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_CELLULAR_CLASS_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_cellular_class_get_string ((MbimCellularClass)tmp));
#elif defined __MBIM_CELLULAR_CLASS_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_cellular_class_build_string_from_mask ((MbimCellularClass)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ProviderId = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ProviderName = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  RoamingText = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  RegistrationFlag = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_REGISTRATION_FLAG_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_registration_flag_get_string ((MbimRegistrationFlag)tmp));
#elif defined __MBIM_REGISTRATION_FLAG_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_registration_flag_build_string_from_mask ((MbimRegistrationFlag)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Signal State */

MbimMessage *
mbim_message_signal_state_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_SIGNAL_STATE,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_signal_state_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message Signal State */

MbimMessage *
mbim_message_signal_state_set_new (
    guint32 signal_strength_interval,
    guint32 rssi_threshold,
    guint32 error_rate_threshold,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_SIGNAL_STATE,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, signal_strength_interval);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, rssi_threshold);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, error_rate_threshold);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_signal_state_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  SignalStrengthInterval = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  RssiThreshold = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ErrorRateThreshold = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Signal State */

gboolean
mbim_message_signal_state_response_parse (
    const MbimMessage *message,
    guint32 *out_rssi,
    guint32 *out_error_rate,
    guint32 *out_signal_strength_interval,
    guint32 *out_rssi_threshold,
    guint32 *out_error_rate_threshold,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'Rssi' variable */
    {
        if ((out_rssi != NULL) && !_mbim_message_read_guint32 (message, offset, out_rssi, error))
            goto out;
        offset += 4;
    }

    /* Read the 'ErrorRate' variable */
    {
        if ((out_error_rate != NULL) && !_mbim_message_read_guint32 (message, offset, out_error_rate, error))
            goto out;
        offset += 4;
    }

    /* Read the 'SignalStrengthInterval' variable */
    {
        if ((out_signal_strength_interval != NULL) && !_mbim_message_read_guint32 (message, offset, out_signal_strength_interval, error))
            goto out;
        offset += 4;
    }

    /* Read the 'RssiThreshold' variable */
    {
        if ((out_rssi_threshold != NULL) && !_mbim_message_read_guint32 (message, offset, out_rssi_threshold, error))
            goto out;
        offset += 4;
    }

    /* Read the 'ErrorRateThreshold' variable */
    {
        if ((out_error_rate_threshold != NULL) && !_mbim_message_read_guint32 (message, offset, out_error_rate_threshold, error))
            goto out;
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_signal_state_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Rssi = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ErrorRate = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  SignalStrengthInterval = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  RssiThreshold = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ErrorRateThreshold = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Notification): MBIM Message Signal State */

gboolean
mbim_message_signal_state_notification_parse (
    const MbimMessage *message,
    guint32 *out_rssi,
    guint32 *out_error_rate,
    guint32 *out_signal_strength_interval,
    guint32 *out_rssi_threshold,
    guint32 *out_error_rate_threshold,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_INDICATE_STATUS) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a notification");
        return FALSE;
    }

    if (!mbim_message_indicate_status_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'Rssi' variable */
    {
        if ((out_rssi != NULL) && !_mbim_message_read_guint32 (message, offset, out_rssi, error))
            goto out;
        offset += 4;
    }

    /* Read the 'ErrorRate' variable */
    {
        if ((out_error_rate != NULL) && !_mbim_message_read_guint32 (message, offset, out_error_rate, error))
            goto out;
        offset += 4;
    }

    /* Read the 'SignalStrengthInterval' variable */
    {
        if ((out_signal_strength_interval != NULL) && !_mbim_message_read_guint32 (message, offset, out_signal_strength_interval, error))
            goto out;
        offset += 4;
    }

    /* Read the 'RssiThreshold' variable */
    {
        if ((out_rssi_threshold != NULL) && !_mbim_message_read_guint32 (message, offset, out_rssi_threshold, error))
            goto out;
        offset += 4;
    }

    /* Read the 'ErrorRateThreshold' variable */
    {
        if ((out_error_rate_threshold != NULL) && !_mbim_message_read_guint32 (message, offset, out_error_rate_threshold, error))
            goto out;
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_signal_state_notification_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Rssi = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ErrorRate = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  SignalStrengthInterval = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  RssiThreshold = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ErrorRateThreshold = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Packet Service */

MbimMessage *
mbim_message_packet_service_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_PACKET_SERVICE,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_packet_service_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message Packet Service */

MbimMessage *
mbim_message_packet_service_set_new (
    MbimPacketServiceAction packet_service_action,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_PACKET_SERVICE,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, packet_service_action);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_packet_service_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  PacketServiceAction = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_PACKET_SERVICE_ACTION_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_packet_service_action_get_string ((MbimPacketServiceAction)tmp));
#elif defined __MBIM_PACKET_SERVICE_ACTION_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_packet_service_action_build_string_from_mask ((MbimPacketServiceAction)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Packet Service */

gboolean
mbim_message_packet_service_response_parse (
    const MbimMessage *message,
    guint32 *out_nw_error,
    MbimPacketServiceState *out_packet_service_state,
    MbimDataClass *out_highest_available_data_class,
    guint64 *out_uplink_speed,
    guint64 *out_downlink_speed,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'NwError' variable */
    {
        if ((out_nw_error != NULL) && !_mbim_message_read_guint32 (message, offset, out_nw_error, error))
            goto out;
        offset += 4;
    }

    /* Read the 'PacketServiceState' variable */
    {
        if (out_packet_service_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_packet_service_state = (MbimPacketServiceState)aux;
        }
        offset += 4;
    }

    /* Read the 'HighestAvailableDataClass' variable */
    {
        if (out_highest_available_data_class != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_highest_available_data_class = (MbimDataClass)aux;
        }
        offset += 4;
    }

    /* Read the 'UplinkSpeed' variable */
    {
        if ((out_uplink_speed != NULL) && !_mbim_message_read_guint64 (message, offset, out_uplink_speed, error))
            goto out;
        offset += 8;
    }

    /* Read the 'DownlinkSpeed' variable */
    {
        if ((out_downlink_speed != NULL) && !_mbim_message_read_guint64 (message, offset, out_downlink_speed, error))
            goto out;
        offset += 8;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_packet_service_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  NwError = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PacketServiceState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_PACKET_SERVICE_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_packet_service_state_get_string ((MbimPacketServiceState)tmp));
#elif defined __MBIM_PACKET_SERVICE_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_packet_service_state_build_string_from_mask ((MbimPacketServiceState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  HighestAvailableDataClass = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_DATA_CLASS_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_data_class_get_string ((MbimDataClass)tmp));
#elif defined __MBIM_DATA_CLASS_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_data_class_build_string_from_mask ((MbimDataClass)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  UplinkSpeed = ", line_prefix);
    {
        guint64 tmp;

        if (!_mbim_message_read_guint64 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%" G_GUINT64_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  DownlinkSpeed = ", line_prefix);
    {
        guint64 tmp;

        if (!_mbim_message_read_guint64 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%" G_GUINT64_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Notification): MBIM Message Packet Service */

gboolean
mbim_message_packet_service_notification_parse (
    const MbimMessage *message,
    guint32 *out_nw_error,
    MbimPacketServiceState *out_packet_service_state,
    MbimDataClass *out_highest_available_data_class,
    guint64 *out_uplink_speed,
    guint64 *out_downlink_speed,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_INDICATE_STATUS) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a notification");
        return FALSE;
    }

    if (!mbim_message_indicate_status_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'NwError' variable */
    {
        if ((out_nw_error != NULL) && !_mbim_message_read_guint32 (message, offset, out_nw_error, error))
            goto out;
        offset += 4;
    }

    /* Read the 'PacketServiceState' variable */
    {
        if (out_packet_service_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_packet_service_state = (MbimPacketServiceState)aux;
        }
        offset += 4;
    }

    /* Read the 'HighestAvailableDataClass' variable */
    {
        if (out_highest_available_data_class != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_highest_available_data_class = (MbimDataClass)aux;
        }
        offset += 4;
    }

    /* Read the 'UplinkSpeed' variable */
    {
        if ((out_uplink_speed != NULL) && !_mbim_message_read_guint64 (message, offset, out_uplink_speed, error))
            goto out;
        offset += 8;
    }

    /* Read the 'DownlinkSpeed' variable */
    {
        if ((out_downlink_speed != NULL) && !_mbim_message_read_guint64 (message, offset, out_downlink_speed, error))
            goto out;
        offset += 8;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_packet_service_notification_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  NwError = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PacketServiceState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_PACKET_SERVICE_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_packet_service_state_get_string ((MbimPacketServiceState)tmp));
#elif defined __MBIM_PACKET_SERVICE_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_packet_service_state_build_string_from_mask ((MbimPacketServiceState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  HighestAvailableDataClass = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_DATA_CLASS_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_data_class_get_string ((MbimDataClass)tmp));
#elif defined __MBIM_DATA_CLASS_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_data_class_build_string_from_mask ((MbimDataClass)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  UplinkSpeed = ", line_prefix);
    {
        guint64 tmp;

        if (!_mbim_message_read_guint64 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%" G_GUINT64_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  DownlinkSpeed = ", line_prefix);
    {
        guint64 tmp;

        if (!_mbim_message_read_guint64 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%" G_GUINT64_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Connect */

MbimMessage *
mbim_message_connect_query_new (
    guint32 session_id,
    MbimActivationState activation_state,
    MbimVoiceCallState voice_call_state,
    MbimContextIpType ip_type,
    const MbimUuid *context_type,
    guint32 nw_error,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_CONNECT,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);
    {
        _mbim_message_command_builder_append_guint32 (builder, session_id);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, activation_state);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, voice_call_state);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, ip_type);
    }
    {
        _mbim_message_command_builder_append_uuid (builder, context_type);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, nw_error);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_connect_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  SessionId = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ActivationState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_ACTIVATION_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_activation_state_get_string ((MbimActivationState)tmp));
#elif defined __MBIM_ACTIVATION_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_activation_state_build_string_from_mask ((MbimActivationState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  VoiceCallState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_VOICE_CALL_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_voice_call_state_get_string ((MbimVoiceCallState)tmp));
#elif defined __MBIM_VOICE_CALL_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_voice_call_state_build_string_from_mask ((MbimVoiceCallState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IpType = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_CONTEXT_IP_TYPE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_context_ip_type_get_string ((MbimContextIpType)tmp));
#elif defined __MBIM_CONTEXT_IP_TYPE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_context_ip_type_build_string_from_mask ((MbimContextIpType)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ContextType = ", line_prefix);
    {
        const MbimUuid   *tmp;
        g_autofree gchar *tmpstr = NULL;

        if (!_mbim_message_read_uuid (message, offset, &tmp, &inner_error))
            goto out;
        offset += 16;
        tmpstr = mbim_uuid_get_printable (tmp);
        g_string_append_printf (str, "'%s'", tmpstr);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  NwError = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message Connect */

MbimMessage *
mbim_message_connect_set_new (
    guint32 session_id,
    MbimActivationCommand activation_command,
    const gchar *access_string,
    const gchar *user_name,
    const gchar *password,
    MbimCompression compression,
    MbimAuthProtocol auth_protocol,
    MbimContextIpType ip_type,
    const MbimUuid *context_type,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_CONNECT,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, session_id);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, activation_command);
    }
    {
        _mbim_message_command_builder_append_string (builder, access_string);
    }
    {
        _mbim_message_command_builder_append_string (builder, user_name);
    }
    {
        _mbim_message_command_builder_append_string (builder, password);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, compression);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, auth_protocol);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, ip_type);
    }
    {
        _mbim_message_command_builder_append_uuid (builder, context_type);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_connect_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  SessionId = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ActivationCommand = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_ACTIVATION_COMMAND_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_activation_command_get_string ((MbimActivationCommand)tmp));
#elif defined __MBIM_ACTIVATION_COMMAND_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_activation_command_build_string_from_mask ((MbimActivationCommand)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  AccessString = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  UserName = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Password = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Compression = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_COMPRESSION_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_compression_get_string ((MbimCompression)tmp));
#elif defined __MBIM_COMPRESSION_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_compression_build_string_from_mask ((MbimCompression)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  AuthProtocol = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_AUTH_PROTOCOL_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_auth_protocol_get_string ((MbimAuthProtocol)tmp));
#elif defined __MBIM_AUTH_PROTOCOL_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_auth_protocol_build_string_from_mask ((MbimAuthProtocol)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IpType = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_CONTEXT_IP_TYPE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_context_ip_type_get_string ((MbimContextIpType)tmp));
#elif defined __MBIM_CONTEXT_IP_TYPE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_context_ip_type_build_string_from_mask ((MbimContextIpType)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ContextType = ", line_prefix);
    {
        const MbimUuid   *tmp;
        g_autofree gchar *tmpstr = NULL;

        if (!_mbim_message_read_uuid (message, offset, &tmp, &inner_error))
            goto out;
        offset += 16;
        tmpstr = mbim_uuid_get_printable (tmp);
        g_string_append_printf (str, "'%s'", tmpstr);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Connect */

gboolean
mbim_message_connect_response_parse (
    const MbimMessage *message,
    guint32 *out_session_id,
    MbimActivationState *out_activation_state,
    MbimVoiceCallState *out_voice_call_state,
    MbimContextIpType *out_ip_type,
    const MbimUuid **out_context_type,
    guint32 *out_nw_error,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'SessionId' variable */
    {
        if ((out_session_id != NULL) && !_mbim_message_read_guint32 (message, offset, out_session_id, error))
            goto out;
        offset += 4;
    }

    /* Read the 'ActivationState' variable */
    {
        if (out_activation_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_activation_state = (MbimActivationState)aux;
        }
        offset += 4;
    }

    /* Read the 'VoiceCallState' variable */
    {
        if (out_voice_call_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_voice_call_state = (MbimVoiceCallState)aux;
        }
        offset += 4;
    }

    /* Read the 'IpType' variable */
    {
        if (out_ip_type != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_ip_type = (MbimContextIpType)aux;
        }
        offset += 4;
    }

    /* Read the 'ContextType' variable */
    {
        if ((out_context_type != NULL) && !_mbim_message_read_uuid (message, offset, out_context_type, error))
            goto out;
        offset += 16;
    }

    /* Read the 'NwError' variable */
    {
        if ((out_nw_error != NULL) && !_mbim_message_read_guint32 (message, offset, out_nw_error, error))
            goto out;
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_connect_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  SessionId = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ActivationState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_ACTIVATION_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_activation_state_get_string ((MbimActivationState)tmp));
#elif defined __MBIM_ACTIVATION_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_activation_state_build_string_from_mask ((MbimActivationState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  VoiceCallState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_VOICE_CALL_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_voice_call_state_get_string ((MbimVoiceCallState)tmp));
#elif defined __MBIM_VOICE_CALL_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_voice_call_state_build_string_from_mask ((MbimVoiceCallState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IpType = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_CONTEXT_IP_TYPE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_context_ip_type_get_string ((MbimContextIpType)tmp));
#elif defined __MBIM_CONTEXT_IP_TYPE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_context_ip_type_build_string_from_mask ((MbimContextIpType)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ContextType = ", line_prefix);
    {
        const MbimUuid   *tmp;
        g_autofree gchar *tmpstr = NULL;

        if (!_mbim_message_read_uuid (message, offset, &tmp, &inner_error))
            goto out;
        offset += 16;
        tmpstr = mbim_uuid_get_printable (tmp);
        g_string_append_printf (str, "'%s'", tmpstr);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  NwError = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Notification): MBIM Message Connect */

gboolean
mbim_message_connect_notification_parse (
    const MbimMessage *message,
    guint32 *out_session_id,
    MbimActivationState *out_activation_state,
    MbimVoiceCallState *out_voice_call_state,
    MbimContextIpType *out_ip_type,
    const MbimUuid **out_context_type,
    guint32 *out_nw_error,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_INDICATE_STATUS) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a notification");
        return FALSE;
    }

    if (!mbim_message_indicate_status_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'SessionId' variable */
    {
        if ((out_session_id != NULL) && !_mbim_message_read_guint32 (message, offset, out_session_id, error))
            goto out;
        offset += 4;
    }

    /* Read the 'ActivationState' variable */
    {
        if (out_activation_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_activation_state = (MbimActivationState)aux;
        }
        offset += 4;
    }

    /* Read the 'VoiceCallState' variable */
    {
        if (out_voice_call_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_voice_call_state = (MbimVoiceCallState)aux;
        }
        offset += 4;
    }

    /* Read the 'IpType' variable */
    {
        if (out_ip_type != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_ip_type = (MbimContextIpType)aux;
        }
        offset += 4;
    }

    /* Read the 'ContextType' variable */
    {
        if ((out_context_type != NULL) && !_mbim_message_read_uuid (message, offset, out_context_type, error))
            goto out;
        offset += 16;
    }

    /* Read the 'NwError' variable */
    {
        if ((out_nw_error != NULL) && !_mbim_message_read_guint32 (message, offset, out_nw_error, error))
            goto out;
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_connect_notification_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  SessionId = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ActivationState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_ACTIVATION_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_activation_state_get_string ((MbimActivationState)tmp));
#elif defined __MBIM_ACTIVATION_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_activation_state_build_string_from_mask ((MbimActivationState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  VoiceCallState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_VOICE_CALL_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_voice_call_state_get_string ((MbimVoiceCallState)tmp));
#elif defined __MBIM_VOICE_CALL_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_voice_call_state_build_string_from_mask ((MbimVoiceCallState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IpType = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_CONTEXT_IP_TYPE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_context_ip_type_get_string ((MbimContextIpType)tmp));
#elif defined __MBIM_CONTEXT_IP_TYPE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_context_ip_type_build_string_from_mask ((MbimContextIpType)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ContextType = ", line_prefix);
    {
        const MbimUuid   *tmp;
        g_autofree gchar *tmpstr = NULL;

        if (!_mbim_message_read_uuid (message, offset, &tmp, &inner_error))
            goto out;
        offset += 16;
        tmpstr = mbim_uuid_get_printable (tmp);
        g_string_append_printf (str, "'%s'", tmpstr);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  NwError = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Provisioned Contexts */

MbimMessage *
mbim_message_provisioned_contexts_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_PROVISIONED_CONTEXTS,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_provisioned_contexts_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message Provisioned Contexts */

MbimMessage *
mbim_message_provisioned_contexts_set_new (
    guint32 context_id,
    const MbimUuid *context_type,
    const gchar *access_string,
    const gchar *user_name,
    const gchar *password,
    MbimCompression compression,
    MbimAuthProtocol auth_protocol,
    const gchar *provider_id,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_PROVISIONED_CONTEXTS,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, context_id);
    }
    {
        _mbim_message_command_builder_append_uuid (builder, context_type);
    }
    {
        _mbim_message_command_builder_append_string (builder, access_string);
    }
    {
        _mbim_message_command_builder_append_string (builder, user_name);
    }
    {
        _mbim_message_command_builder_append_string (builder, password);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, compression);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, auth_protocol);
    }
    {
        _mbim_message_command_builder_append_string (builder, provider_id);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_provisioned_contexts_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ContextId = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ContextType = ", line_prefix);
    {
        const MbimUuid   *tmp;
        g_autofree gchar *tmpstr = NULL;

        if (!_mbim_message_read_uuid (message, offset, &tmp, &inner_error))
            goto out;
        offset += 16;
        tmpstr = mbim_uuid_get_printable (tmp);
        g_string_append_printf (str, "'%s'", tmpstr);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  AccessString = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  UserName = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Password = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Compression = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_COMPRESSION_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_compression_get_string ((MbimCompression)tmp));
#elif defined __MBIM_COMPRESSION_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_compression_build_string_from_mask ((MbimCompression)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  AuthProtocol = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_AUTH_PROTOCOL_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_auth_protocol_get_string ((MbimAuthProtocol)tmp));
#elif defined __MBIM_AUTH_PROTOCOL_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_auth_protocol_build_string_from_mask ((MbimAuthProtocol)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ProviderId = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Provisioned Contexts */

gboolean
mbim_message_provisioned_contexts_response_parse (
    const MbimMessage *message,
    guint32 *out_provisioned_contexts_count,
    MbimProvisionedContextElementArray **out_provisioned_contexts,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    guint32 _provisioned_contexts_count;
    MbimProvisionedContextElement **_provisioned_contexts = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'ProvisionedContextsCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_provisioned_contexts_count, error))
            goto out;
        if (out_provisioned_contexts_count != NULL)
            *out_provisioned_contexts_count = _provisioned_contexts_count;
        offset += 4;
    }

    /* Read the 'ProvisionedContexts' variable */
    {
        if ((out_provisioned_contexts != NULL) && !_mbim_message_read_mbim_provisioned_context_element_struct_array (message, _provisioned_contexts_count, offset, TRUE, &_provisioned_contexts, error))
            goto out;
        offset += (8 * _provisioned_contexts_count);
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_provisioned_contexts != NULL)
            *out_provisioned_contexts = _provisioned_contexts;
    } else {
        mbim_provisioned_context_element_array_free (_provisioned_contexts);
    }

    return success;
}

static gchar *
mbim_message_provisioned_contexts_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _provisioned_contexts_count;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ProvisionedContextsCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_provisioned_contexts_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _provisioned_contexts_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ProvisionedContexts = ", line_prefix);
    {
        g_autoptr(MbimProvisionedContextElementArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_provisioned_context_element_struct_array (message, _provisioned_contexts_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _provisioned_contexts_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _provisioned_contexts_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_provisioned_context_element_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Notification): MBIM Message Provisioned Contexts */

gboolean
mbim_message_provisioned_contexts_notification_parse (
    const MbimMessage *message,
    guint32 *out_provisioned_contexts_count,
    MbimProvisionedContextElementArray **out_provisioned_contexts,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    guint32 _provisioned_contexts_count;
    MbimProvisionedContextElement **_provisioned_contexts = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_INDICATE_STATUS) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a notification");
        return FALSE;
    }

    if (!mbim_message_indicate_status_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'ProvisionedContextsCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_provisioned_contexts_count, error))
            goto out;
        if (out_provisioned_contexts_count != NULL)
            *out_provisioned_contexts_count = _provisioned_contexts_count;
        offset += 4;
    }

    /* Read the 'ProvisionedContexts' variable */
    {
        if ((out_provisioned_contexts != NULL) && !_mbim_message_read_mbim_provisioned_context_element_struct_array (message, _provisioned_contexts_count, offset, TRUE, &_provisioned_contexts, error))
            goto out;
        offset += (8 * _provisioned_contexts_count);
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_provisioned_contexts != NULL)
            *out_provisioned_contexts = _provisioned_contexts;
    } else {
        mbim_provisioned_context_element_array_free (_provisioned_contexts);
    }

    return success;
}

static gchar *
mbim_message_provisioned_contexts_notification_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _provisioned_contexts_count;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ProvisionedContextsCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_provisioned_contexts_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _provisioned_contexts_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ProvisionedContexts = ", line_prefix);
    {
        g_autoptr(MbimProvisionedContextElementArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_provisioned_context_element_struct_array (message, _provisioned_contexts_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _provisioned_contexts_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _provisioned_contexts_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_provisioned_context_element_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message Service Activation */

MbimMessage *
mbim_message_service_activation_set_new (
    const guint32 buffer_size,
    const guint8 *buffer,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_SERVICE_ACTIVATION,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_byte_array (builder, FALSE, FALSE, TRUE, buffer, buffer_size);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_service_activation_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Buffer = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 0, &tmp, &tmpsize, &inner_error))
            goto out;
        offset += tmpsize;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Service Activation */

gboolean
mbim_message_service_activation_response_parse (
    const MbimMessage *message,
    MbimNwError *out_nw_error,
    guint32 *out_buffer_size,
    const guint8 **out_buffer,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'NwError' variable */
    {
        if (out_nw_error != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_nw_error = (MbimNwError)aux;
        }
        offset += 4;
    }

    /* Read the 'Buffer' variable */
    {
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 0, &tmp, &tmpsize, error))
            goto out;
        if (out_buffer != NULL)
            *out_buffer = tmp;
        if (out_buffer_size != NULL)
            *out_buffer_size = tmpsize;
        offset += tmpsize;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_service_activation_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  NwError = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_NW_ERROR_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_nw_error_get_string ((MbimNwError)tmp));
#elif defined __MBIM_NW_ERROR_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_nw_error_build_string_from_mask ((MbimNwError)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Buffer = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 0, &tmp, &tmpsize, &inner_error))
            goto out;
        offset += tmpsize;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message IP Configuration */

MbimMessage *
mbim_message_ip_configuration_query_new (
    guint32 session_id,
    MbimIPConfigurationAvailableFlag ipv4_configuration_available,
    MbimIPConfigurationAvailableFlag ipv6_configuration_available,
    guint32 ipv4_address_count,
    const MbimIPv4Element *const *ipv4_address,
    guint32 ipv6_address_count,
    const MbimIPv6Element *const *ipv6_address,
    const MbimIPv4 *ipv4_gateway,
    const MbimIPv6 *ipv6_gateway,
    guint32 ipv4_dns_server_count,
    const MbimIPv4 *ipv4_dns_server,
    guint32 ipv6_dns_server_count,
    const MbimIPv6 *ipv6_dns_server,
    guint32 ipv4_mtu,
    guint32 ipv6_mtu,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_IP_CONFIGURATION,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);
    {
        _mbim_message_command_builder_append_guint32 (builder, session_id);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, ipv4_configuration_available);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, ipv6_configuration_available);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, ipv4_address_count);
    }
    {
        _mbim_message_command_builder_append_mbim_ipv4_element_struct_array (builder, ipv4_address, ipv4_address_count, FALSE);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, ipv6_address_count);
    }
    {
        _mbim_message_command_builder_append_mbim_ipv6_element_struct_array (builder, ipv6_address, ipv6_address_count, FALSE);
    }
    {
        _mbim_message_command_builder_append_ipv4 (builder, ipv4_gateway, TRUE);
    }
    {
        _mbim_message_command_builder_append_ipv6 (builder, ipv6_gateway, TRUE);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, ipv4_dns_server_count);
    }
    {
        _mbim_message_command_builder_append_ipv4_array (builder, ipv4_dns_server, ipv4_dns_server_count);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, ipv6_dns_server_count);
    }
    {
        _mbim_message_command_builder_append_ipv6_array (builder, ipv6_dns_server, ipv6_dns_server_count);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, ipv4_mtu);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, ipv6_mtu);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_ip_configuration_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _ipv4_address_count;
    guint32 _ipv6_address_count;
    guint32 _ipv4_dns_server_count;
    guint32 _ipv6_dns_server_count;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  SessionId = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4ConfigurationAvailable = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_ip_configuration_available_flag_get_string ((MbimIPConfigurationAvailableFlag)tmp));
#elif defined __MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_ip_configuration_available_flag_build_string_from_mask ((MbimIPConfigurationAvailableFlag)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6ConfigurationAvailable = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_ip_configuration_available_flag_get_string ((MbimIPConfigurationAvailableFlag)tmp));
#elif defined __MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_ip_configuration_available_flag_build_string_from_mask ((MbimIPConfigurationAvailableFlag)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4AddressCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv4_address_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _ipv4_address_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4Address = ", line_prefix);
    {
        g_autoptr(MbimIPv4ElementArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_ipv4_element_struct_array (message, _ipv4_address_count, offset, FALSE, &tmp, &inner_error))
            goto out;
        offset += 4;
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _ipv4_address_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_ipv4_element_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6AddressCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv6_address_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _ipv6_address_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6Address = ", line_prefix);
    {
        g_autoptr(MbimIPv6ElementArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_ipv6_element_struct_array (message, _ipv6_address_count, offset, FALSE, &tmp, &inner_error))
            goto out;
        offset += 4;
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _ipv6_address_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_ipv6_element_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4Gateway = ", line_prefix);
    {
        const MbimIPv4 *tmp;
        guint array_size;
        guint i;

        array_size = 1;
        if (!_mbim_message_read_ipv4 (message, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append (str, "'");
        if (tmp) {
            for (i = 0; i < array_size; i++) {
                g_autoptr(GInetAddress)  addr = NULL;
                g_autofree gchar        *tmpstr = NULL;

                addr = g_inet_address_new_from_bytes ((guint8 *)&(tmp[i].addr), G_SOCKET_FAMILY_IPV4);
                tmpstr = g_inet_address_to_string (addr);
                g_string_append_printf (str, "%s", tmpstr);
                if (i < (array_size - 1))
                    g_string_append (str, ", ");
            }
        }
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6Gateway = ", line_prefix);
    {
        const MbimIPv6 *tmp;
        guint array_size;
        guint i;

        array_size = 1;
        if (!_mbim_message_read_ipv6 (message, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append (str, "'");
        if (tmp) {
            for (i = 0; i < array_size; i++) {
                g_autoptr(GInetAddress)  addr = NULL;
                g_autofree gchar        *tmpstr = NULL;

                addr = g_inet_address_new_from_bytes ((guint8 *)&(tmp[i].addr), G_SOCKET_FAMILY_IPV6);
                tmpstr = g_inet_address_to_string (addr);
                g_string_append_printf (str, "%s", tmpstr);
                if (i < (array_size - 1))
                    g_string_append (str, ", ");
            }
        }
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4DnsServerCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv4_dns_server_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _ipv4_dns_server_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4DnsServer = ", line_prefix);
    {
        g_autofree MbimIPv4 *tmp = NULL;
        guint array_size;
        guint i;

        array_size = _ipv4_dns_server_count;
        if (!_mbim_message_read_ipv4_array (message, _ipv4_dns_server_count, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append (str, "'");
        if (tmp) {
            for (i = 0; i < array_size; i++) {
                g_autoptr(GInetAddress)  addr = NULL;
                g_autofree gchar        *tmpstr = NULL;

                addr = g_inet_address_new_from_bytes ((guint8 *)&(tmp[i].addr), G_SOCKET_FAMILY_IPV4);
                tmpstr = g_inet_address_to_string (addr);
                g_string_append_printf (str, "%s", tmpstr);
                if (i < (array_size - 1))
                    g_string_append (str, ", ");
            }
        }
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6DnsServerCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv6_dns_server_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _ipv6_dns_server_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6DnsServer = ", line_prefix);
    {
        g_autofree MbimIPv6 *tmp = NULL;
        guint array_size;
        guint i;

        array_size = _ipv6_dns_server_count;
        if (!_mbim_message_read_ipv6_array (message, _ipv6_dns_server_count, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append (str, "'");
        if (tmp) {
            for (i = 0; i < array_size; i++) {
                g_autoptr(GInetAddress)  addr = NULL;
                g_autofree gchar        *tmpstr = NULL;

                addr = g_inet_address_new_from_bytes ((guint8 *)&(tmp[i].addr), G_SOCKET_FAMILY_IPV6);
                tmpstr = g_inet_address_to_string (addr);
                g_string_append_printf (str, "%s", tmpstr);
                if (i < (array_size - 1))
                    g_string_append (str, ", ");
            }
        }
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4Mtu = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6Mtu = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message IP Configuration */

gboolean
mbim_message_ip_configuration_response_parse (
    const MbimMessage *message,
    guint32 *out_session_id,
    MbimIPConfigurationAvailableFlag *out_ipv4_configuration_available,
    MbimIPConfigurationAvailableFlag *out_ipv6_configuration_available,
    guint32 *out_ipv4_address_count,
    MbimIPv4ElementArray **out_ipv4_address,
    guint32 *out_ipv6_address_count,
    MbimIPv6ElementArray **out_ipv6_address,
    const MbimIPv4 **out_ipv4_gateway,
    const MbimIPv6 **out_ipv6_gateway,
    guint32 *out_ipv4_dns_server_count,
    MbimIPv4 **out_ipv4_dns_server,
    guint32 *out_ipv6_dns_server_count,
    MbimIPv6 **out_ipv6_dns_server,
    guint32 *out_ipv4_mtu,
    guint32 *out_ipv6_mtu,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    guint32 _ipv4_address_count;
    MbimIPv4Element **_ipv4_address = NULL;
    guint32 _ipv6_address_count;
    MbimIPv6Element **_ipv6_address = NULL;
    guint32 _ipv4_dns_server_count;
    MbimIPv4 *_ipv4_dns_server = NULL;
    guint32 _ipv6_dns_server_count;
    MbimIPv6 *_ipv6_dns_server = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'SessionId' variable */
    {
        if ((out_session_id != NULL) && !_mbim_message_read_guint32 (message, offset, out_session_id, error))
            goto out;
        offset += 4;
    }

    /* Read the 'IPv4ConfigurationAvailable' variable */
    {
        if (out_ipv4_configuration_available != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_ipv4_configuration_available = (MbimIPConfigurationAvailableFlag)aux;
        }
        offset += 4;
    }

    /* Read the 'IPv6ConfigurationAvailable' variable */
    {
        if (out_ipv6_configuration_available != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_ipv6_configuration_available = (MbimIPConfigurationAvailableFlag)aux;
        }
        offset += 4;
    }

    /* Read the 'IPv4AddressCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv4_address_count, error))
            goto out;
        if (out_ipv4_address_count != NULL)
            *out_ipv4_address_count = _ipv4_address_count;
        offset += 4;
    }

    /* Read the 'IPv4Address' variable */
    {
        if ((out_ipv4_address != NULL) && !_mbim_message_read_mbim_ipv4_element_struct_array (message, _ipv4_address_count, offset, FALSE, &_ipv4_address, error))
            goto out;
        offset += 4;
    }

    /* Read the 'IPv6AddressCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv6_address_count, error))
            goto out;
        if (out_ipv6_address_count != NULL)
            *out_ipv6_address_count = _ipv6_address_count;
        offset += 4;
    }

    /* Read the 'IPv6Address' variable */
    {
        if ((out_ipv6_address != NULL) && !_mbim_message_read_mbim_ipv6_element_struct_array (message, _ipv6_address_count, offset, FALSE, &_ipv6_address, error))
            goto out;
        offset += 4;
    }

    /* Read the 'IPv4Gateway' variable */
    {
        if ((out_ipv4_gateway != NULL) && !_mbim_message_read_ipv4 (message, offset, TRUE, out_ipv4_gateway, error))
            goto out;
        offset += 4;
    }

    /* Read the 'IPv6Gateway' variable */
    {
        if ((out_ipv6_gateway != NULL) && !_mbim_message_read_ipv6 (message, offset, TRUE, out_ipv6_gateway, error))
            goto out;
        offset += 4;
    }

    /* Read the 'IPv4DnsServerCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv4_dns_server_count, error))
            goto out;
        if (out_ipv4_dns_server_count != NULL)
            *out_ipv4_dns_server_count = _ipv4_dns_server_count;
        offset += 4;
    }

    /* Read the 'IPv4DnsServer' variable */
    {
        if ((out_ipv4_dns_server != NULL) && !_mbim_message_read_ipv4_array (message, _ipv4_dns_server_count, offset, &_ipv4_dns_server, error))
            goto out;
        offset += 4;
    }

    /* Read the 'IPv6DnsServerCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv6_dns_server_count, error))
            goto out;
        if (out_ipv6_dns_server_count != NULL)
            *out_ipv6_dns_server_count = _ipv6_dns_server_count;
        offset += 4;
    }

    /* Read the 'IPv6DnsServer' variable */
    {
        if ((out_ipv6_dns_server != NULL) && !_mbim_message_read_ipv6_array (message, _ipv6_dns_server_count, offset, &_ipv6_dns_server, error))
            goto out;
        offset += 4;
    }

    /* Read the 'IPv4Mtu' variable */
    {
        if ((out_ipv4_mtu != NULL) && !_mbim_message_read_guint32 (message, offset, out_ipv4_mtu, error))
            goto out;
        offset += 4;
    }

    /* Read the 'IPv6Mtu' variable */
    {
        if ((out_ipv6_mtu != NULL) && !_mbim_message_read_guint32 (message, offset, out_ipv6_mtu, error))
            goto out;
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_ipv4_address != NULL)
            *out_ipv4_address = _ipv4_address;
        if (out_ipv6_address != NULL)
            *out_ipv6_address = _ipv6_address;
        if (out_ipv4_dns_server != NULL)
            *out_ipv4_dns_server = _ipv4_dns_server;
        if (out_ipv6_dns_server != NULL)
            *out_ipv6_dns_server = _ipv6_dns_server;
    } else {
        mbim_ipv4_element_array_free (_ipv4_address);
        mbim_ipv6_element_array_free (_ipv6_address);
        g_free (_ipv4_dns_server);
        g_free (_ipv6_dns_server);
    }

    return success;
}

static gchar *
mbim_message_ip_configuration_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _ipv4_address_count;
    guint32 _ipv6_address_count;
    guint32 _ipv4_dns_server_count;
    guint32 _ipv6_dns_server_count;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  SessionId = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4ConfigurationAvailable = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_ip_configuration_available_flag_get_string ((MbimIPConfigurationAvailableFlag)tmp));
#elif defined __MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_ip_configuration_available_flag_build_string_from_mask ((MbimIPConfigurationAvailableFlag)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6ConfigurationAvailable = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_ip_configuration_available_flag_get_string ((MbimIPConfigurationAvailableFlag)tmp));
#elif defined __MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_ip_configuration_available_flag_build_string_from_mask ((MbimIPConfigurationAvailableFlag)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4AddressCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv4_address_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _ipv4_address_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4Address = ", line_prefix);
    {
        g_autoptr(MbimIPv4ElementArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_ipv4_element_struct_array (message, _ipv4_address_count, offset, FALSE, &tmp, &inner_error))
            goto out;
        offset += 4;
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _ipv4_address_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_ipv4_element_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6AddressCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv6_address_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _ipv6_address_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6Address = ", line_prefix);
    {
        g_autoptr(MbimIPv6ElementArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_ipv6_element_struct_array (message, _ipv6_address_count, offset, FALSE, &tmp, &inner_error))
            goto out;
        offset += 4;
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _ipv6_address_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_ipv6_element_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4Gateway = ", line_prefix);
    {
        const MbimIPv4 *tmp;
        guint array_size;
        guint i;

        array_size = 1;
        if (!_mbim_message_read_ipv4 (message, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append (str, "'");
        if (tmp) {
            for (i = 0; i < array_size; i++) {
                g_autoptr(GInetAddress)  addr = NULL;
                g_autofree gchar        *tmpstr = NULL;

                addr = g_inet_address_new_from_bytes ((guint8 *)&(tmp[i].addr), G_SOCKET_FAMILY_IPV4);
                tmpstr = g_inet_address_to_string (addr);
                g_string_append_printf (str, "%s", tmpstr);
                if (i < (array_size - 1))
                    g_string_append (str, ", ");
            }
        }
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6Gateway = ", line_prefix);
    {
        const MbimIPv6 *tmp;
        guint array_size;
        guint i;

        array_size = 1;
        if (!_mbim_message_read_ipv6 (message, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append (str, "'");
        if (tmp) {
            for (i = 0; i < array_size; i++) {
                g_autoptr(GInetAddress)  addr = NULL;
                g_autofree gchar        *tmpstr = NULL;

                addr = g_inet_address_new_from_bytes ((guint8 *)&(tmp[i].addr), G_SOCKET_FAMILY_IPV6);
                tmpstr = g_inet_address_to_string (addr);
                g_string_append_printf (str, "%s", tmpstr);
                if (i < (array_size - 1))
                    g_string_append (str, ", ");
            }
        }
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4DnsServerCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv4_dns_server_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _ipv4_dns_server_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4DnsServer = ", line_prefix);
    {
        g_autofree MbimIPv4 *tmp = NULL;
        guint array_size;
        guint i;

        array_size = _ipv4_dns_server_count;
        if (!_mbim_message_read_ipv4_array (message, _ipv4_dns_server_count, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append (str, "'");
        if (tmp) {
            for (i = 0; i < array_size; i++) {
                g_autoptr(GInetAddress)  addr = NULL;
                g_autofree gchar        *tmpstr = NULL;

                addr = g_inet_address_new_from_bytes ((guint8 *)&(tmp[i].addr), G_SOCKET_FAMILY_IPV4);
                tmpstr = g_inet_address_to_string (addr);
                g_string_append_printf (str, "%s", tmpstr);
                if (i < (array_size - 1))
                    g_string_append (str, ", ");
            }
        }
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6DnsServerCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv6_dns_server_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _ipv6_dns_server_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6DnsServer = ", line_prefix);
    {
        g_autofree MbimIPv6 *tmp = NULL;
        guint array_size;
        guint i;

        array_size = _ipv6_dns_server_count;
        if (!_mbim_message_read_ipv6_array (message, _ipv6_dns_server_count, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append (str, "'");
        if (tmp) {
            for (i = 0; i < array_size; i++) {
                g_autoptr(GInetAddress)  addr = NULL;
                g_autofree gchar        *tmpstr = NULL;

                addr = g_inet_address_new_from_bytes ((guint8 *)&(tmp[i].addr), G_SOCKET_FAMILY_IPV6);
                tmpstr = g_inet_address_to_string (addr);
                g_string_append_printf (str, "%s", tmpstr);
                if (i < (array_size - 1))
                    g_string_append (str, ", ");
            }
        }
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4Mtu = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6Mtu = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Notification): MBIM Message IP Configuration */

gboolean
mbim_message_ip_configuration_notification_parse (
    const MbimMessage *message,
    guint32 *out_session_id,
    MbimIPConfigurationAvailableFlag *out_ipv4_configuration_available,
    MbimIPConfigurationAvailableFlag *out_ipv6_configuration_available,
    guint32 *out_ipv4_address_count,
    MbimIPv4ElementArray **out_ipv4_address,
    guint32 *out_ipv6_address_count,
    MbimIPv6ElementArray **out_ipv6_address,
    const MbimIPv4 **out_ipv4_gateway,
    const MbimIPv6 **out_ipv6_gateway,
    guint32 *out_ipv4_dns_server_count,
    MbimIPv4 **out_ipv4_dns_server,
    guint32 *out_ipv6_dns_server_count,
    MbimIPv6 **out_ipv6_dns_server,
    guint32 *out_ipv4_mtu,
    guint32 *out_ipv6_mtu,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    guint32 _ipv4_address_count;
    MbimIPv4Element **_ipv4_address = NULL;
    guint32 _ipv6_address_count;
    MbimIPv6Element **_ipv6_address = NULL;
    guint32 _ipv4_dns_server_count;
    MbimIPv4 *_ipv4_dns_server = NULL;
    guint32 _ipv6_dns_server_count;
    MbimIPv6 *_ipv6_dns_server = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_INDICATE_STATUS) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a notification");
        return FALSE;
    }

    if (!mbim_message_indicate_status_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'SessionId' variable */
    {
        if ((out_session_id != NULL) && !_mbim_message_read_guint32 (message, offset, out_session_id, error))
            goto out;
        offset += 4;
    }

    /* Read the 'IPv4ConfigurationAvailable' variable */
    {
        if (out_ipv4_configuration_available != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_ipv4_configuration_available = (MbimIPConfigurationAvailableFlag)aux;
        }
        offset += 4;
    }

    /* Read the 'IPv6ConfigurationAvailable' variable */
    {
        if (out_ipv6_configuration_available != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_ipv6_configuration_available = (MbimIPConfigurationAvailableFlag)aux;
        }
        offset += 4;
    }

    /* Read the 'IPv4AddressCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv4_address_count, error))
            goto out;
        if (out_ipv4_address_count != NULL)
            *out_ipv4_address_count = _ipv4_address_count;
        offset += 4;
    }

    /* Read the 'IPv4Address' variable */
    {
        if ((out_ipv4_address != NULL) && !_mbim_message_read_mbim_ipv4_element_struct_array (message, _ipv4_address_count, offset, FALSE, &_ipv4_address, error))
            goto out;
        offset += 4;
    }

    /* Read the 'IPv6AddressCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv6_address_count, error))
            goto out;
        if (out_ipv6_address_count != NULL)
            *out_ipv6_address_count = _ipv6_address_count;
        offset += 4;
    }

    /* Read the 'IPv6Address' variable */
    {
        if ((out_ipv6_address != NULL) && !_mbim_message_read_mbim_ipv6_element_struct_array (message, _ipv6_address_count, offset, FALSE, &_ipv6_address, error))
            goto out;
        offset += 4;
    }

    /* Read the 'IPv4Gateway' variable */
    {
        if ((out_ipv4_gateway != NULL) && !_mbim_message_read_ipv4 (message, offset, TRUE, out_ipv4_gateway, error))
            goto out;
        offset += 4;
    }

    /* Read the 'IPv6Gateway' variable */
    {
        if ((out_ipv6_gateway != NULL) && !_mbim_message_read_ipv6 (message, offset, TRUE, out_ipv6_gateway, error))
            goto out;
        offset += 4;
    }

    /* Read the 'IPv4DnsServerCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv4_dns_server_count, error))
            goto out;
        if (out_ipv4_dns_server_count != NULL)
            *out_ipv4_dns_server_count = _ipv4_dns_server_count;
        offset += 4;
    }

    /* Read the 'IPv4DnsServer' variable */
    {
        if ((out_ipv4_dns_server != NULL) && !_mbim_message_read_ipv4_array (message, _ipv4_dns_server_count, offset, &_ipv4_dns_server, error))
            goto out;
        offset += 4;
    }

    /* Read the 'IPv6DnsServerCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv6_dns_server_count, error))
            goto out;
        if (out_ipv6_dns_server_count != NULL)
            *out_ipv6_dns_server_count = _ipv6_dns_server_count;
        offset += 4;
    }

    /* Read the 'IPv6DnsServer' variable */
    {
        if ((out_ipv6_dns_server != NULL) && !_mbim_message_read_ipv6_array (message, _ipv6_dns_server_count, offset, &_ipv6_dns_server, error))
            goto out;
        offset += 4;
    }

    /* Read the 'IPv4Mtu' variable */
    {
        if ((out_ipv4_mtu != NULL) && !_mbim_message_read_guint32 (message, offset, out_ipv4_mtu, error))
            goto out;
        offset += 4;
    }

    /* Read the 'IPv6Mtu' variable */
    {
        if ((out_ipv6_mtu != NULL) && !_mbim_message_read_guint32 (message, offset, out_ipv6_mtu, error))
            goto out;
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_ipv4_address != NULL)
            *out_ipv4_address = _ipv4_address;
        if (out_ipv6_address != NULL)
            *out_ipv6_address = _ipv6_address;
        if (out_ipv4_dns_server != NULL)
            *out_ipv4_dns_server = _ipv4_dns_server;
        if (out_ipv6_dns_server != NULL)
            *out_ipv6_dns_server = _ipv6_dns_server;
    } else {
        mbim_ipv4_element_array_free (_ipv4_address);
        mbim_ipv6_element_array_free (_ipv6_address);
        g_free (_ipv4_dns_server);
        g_free (_ipv6_dns_server);
    }

    return success;
}

static gchar *
mbim_message_ip_configuration_notification_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _ipv4_address_count;
    guint32 _ipv6_address_count;
    guint32 _ipv4_dns_server_count;
    guint32 _ipv6_dns_server_count;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  SessionId = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4ConfigurationAvailable = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_ip_configuration_available_flag_get_string ((MbimIPConfigurationAvailableFlag)tmp));
#elif defined __MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_ip_configuration_available_flag_build_string_from_mask ((MbimIPConfigurationAvailableFlag)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6ConfigurationAvailable = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_ip_configuration_available_flag_get_string ((MbimIPConfigurationAvailableFlag)tmp));
#elif defined __MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_ip_configuration_available_flag_build_string_from_mask ((MbimIPConfigurationAvailableFlag)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4AddressCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv4_address_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _ipv4_address_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4Address = ", line_prefix);
    {
        g_autoptr(MbimIPv4ElementArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_ipv4_element_struct_array (message, _ipv4_address_count, offset, FALSE, &tmp, &inner_error))
            goto out;
        offset += 4;
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _ipv4_address_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_ipv4_element_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6AddressCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv6_address_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _ipv6_address_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6Address = ", line_prefix);
    {
        g_autoptr(MbimIPv6ElementArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_ipv6_element_struct_array (message, _ipv6_address_count, offset, FALSE, &tmp, &inner_error))
            goto out;
        offset += 4;
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _ipv6_address_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_ipv6_element_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4Gateway = ", line_prefix);
    {
        const MbimIPv4 *tmp;
        guint array_size;
        guint i;

        array_size = 1;
        if (!_mbim_message_read_ipv4 (message, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append (str, "'");
        if (tmp) {
            for (i = 0; i < array_size; i++) {
                g_autoptr(GInetAddress)  addr = NULL;
                g_autofree gchar        *tmpstr = NULL;

                addr = g_inet_address_new_from_bytes ((guint8 *)&(tmp[i].addr), G_SOCKET_FAMILY_IPV4);
                tmpstr = g_inet_address_to_string (addr);
                g_string_append_printf (str, "%s", tmpstr);
                if (i < (array_size - 1))
                    g_string_append (str, ", ");
            }
        }
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6Gateway = ", line_prefix);
    {
        const MbimIPv6 *tmp;
        guint array_size;
        guint i;

        array_size = 1;
        if (!_mbim_message_read_ipv6 (message, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append (str, "'");
        if (tmp) {
            for (i = 0; i < array_size; i++) {
                g_autoptr(GInetAddress)  addr = NULL;
                g_autofree gchar        *tmpstr = NULL;

                addr = g_inet_address_new_from_bytes ((guint8 *)&(tmp[i].addr), G_SOCKET_FAMILY_IPV6);
                tmpstr = g_inet_address_to_string (addr);
                g_string_append_printf (str, "%s", tmpstr);
                if (i < (array_size - 1))
                    g_string_append (str, ", ");
            }
        }
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4DnsServerCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv4_dns_server_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _ipv4_dns_server_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4DnsServer = ", line_prefix);
    {
        g_autofree MbimIPv4 *tmp = NULL;
        guint array_size;
        guint i;

        array_size = _ipv4_dns_server_count;
        if (!_mbim_message_read_ipv4_array (message, _ipv4_dns_server_count, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append (str, "'");
        if (tmp) {
            for (i = 0; i < array_size; i++) {
                g_autoptr(GInetAddress)  addr = NULL;
                g_autofree gchar        *tmpstr = NULL;

                addr = g_inet_address_new_from_bytes ((guint8 *)&(tmp[i].addr), G_SOCKET_FAMILY_IPV4);
                tmpstr = g_inet_address_to_string (addr);
                g_string_append_printf (str, "%s", tmpstr);
                if (i < (array_size - 1))
                    g_string_append (str, ", ");
            }
        }
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6DnsServerCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_ipv6_dns_server_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _ipv6_dns_server_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6DnsServer = ", line_prefix);
    {
        g_autofree MbimIPv6 *tmp = NULL;
        guint array_size;
        guint i;

        array_size = _ipv6_dns_server_count;
        if (!_mbim_message_read_ipv6_array (message, _ipv6_dns_server_count, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append (str, "'");
        if (tmp) {
            for (i = 0; i < array_size; i++) {
                g_autoptr(GInetAddress)  addr = NULL;
                g_autofree gchar        *tmpstr = NULL;

                addr = g_inet_address_new_from_bytes ((guint8 *)&(tmp[i].addr), G_SOCKET_FAMILY_IPV6);
                tmpstr = g_inet_address_to_string (addr);
                g_string_append_printf (str, "%s", tmpstr);
                if (i < (array_size - 1))
                    g_string_append (str, ", ");
            }
        }
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv4Mtu = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IPv6Mtu = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Device Services */

MbimMessage *
mbim_message_device_services_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_DEVICE_SERVICES,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_device_services_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Device Services */

gboolean
mbim_message_device_services_response_parse (
    const MbimMessage *message,
    guint32 *out_device_services_count,
    guint32 *out_max_dss_sessions,
    MbimDeviceServiceElementArray **out_device_services,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    guint32 _device_services_count;
    MbimDeviceServiceElement **_device_services = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'DeviceServicesCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_device_services_count, error))
            goto out;
        if (out_device_services_count != NULL)
            *out_device_services_count = _device_services_count;
        offset += 4;
    }

    /* Read the 'MaxDssSessions' variable */
    {
        if ((out_max_dss_sessions != NULL) && !_mbim_message_read_guint32 (message, offset, out_max_dss_sessions, error))
            goto out;
        offset += 4;
    }

    /* Read the 'DeviceServices' variable */
    {
        if ((out_device_services != NULL) && !_mbim_message_read_mbim_device_service_element_struct_array (message, _device_services_count, offset, TRUE, &_device_services, error))
            goto out;
        offset += (8 * _device_services_count);
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_device_services != NULL)
            *out_device_services = _device_services;
    } else {
        mbim_device_service_element_array_free (_device_services);
    }

    return success;
}

static gchar *
mbim_message_device_services_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _device_services_count;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  DeviceServicesCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_device_services_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _device_services_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  MaxDssSessions = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  DeviceServices = ", line_prefix);
    {
        g_autoptr(MbimDeviceServiceElementArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_device_service_element_struct_array (message, _device_services_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _device_services_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _device_services_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_device_service_element_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message Device Service Subscribe List */

MbimMessage *
mbim_message_device_service_subscribe_list_set_new (
    guint32 events_count,
    const MbimEventEntry *const *events,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_DEVICE_SERVICE_SUBSCRIBE_LIST,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, events_count);
    }
    {
        _mbim_message_command_builder_append_mbim_event_entry_struct_array (builder, events, events_count, TRUE);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_device_service_subscribe_list_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _events_count;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  EventsCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_events_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _events_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Events = ", line_prefix);
    {
        g_autoptr(MbimEventEntryArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_event_entry_struct_array (message, _events_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _events_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _events_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_event_entry_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Device Service Subscribe List */

gboolean
mbim_message_device_service_subscribe_list_response_parse (
    const MbimMessage *message,
    guint32 *out_events_count,
    MbimEventEntryArray **out_events,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    guint32 _events_count;
    MbimEventEntry **_events = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'EventsCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_events_count, error))
            goto out;
        if (out_events_count != NULL)
            *out_events_count = _events_count;
        offset += 4;
    }

    /* Read the 'Events' variable */
    {
        if ((out_events != NULL) && !_mbim_message_read_mbim_event_entry_struct_array (message, _events_count, offset, TRUE, &_events, error))
            goto out;
        offset += (8 * _events_count);
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_events != NULL)
            *out_events = _events;
    } else {
        mbim_event_entry_array_free (_events);
    }

    return success;
}

static gchar *
mbim_message_device_service_subscribe_list_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _events_count;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  EventsCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_events_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _events_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Events = ", line_prefix);
    {
        g_autoptr(MbimEventEntryArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_event_entry_struct_array (message, _events_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _events_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _events_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_event_entry_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Packet Statistics */

MbimMessage *
mbim_message_packet_statistics_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_PACKET_STATISTICS,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_packet_statistics_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Packet Statistics */

gboolean
mbim_message_packet_statistics_response_parse (
    const MbimMessage *message,
    guint32 *out_in_discards,
    guint32 *out_in_errors,
    guint64 *out_in_octets,
    guint64 *out_in_packets,
    guint64 *out_out_octets,
    guint64 *out_out_packets,
    guint32 *out_out_errors,
    guint32 *out_out_discards,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'InDiscards' variable */
    {
        if ((out_in_discards != NULL) && !_mbim_message_read_guint32 (message, offset, out_in_discards, error))
            goto out;
        offset += 4;
    }

    /* Read the 'InErrors' variable */
    {
        if ((out_in_errors != NULL) && !_mbim_message_read_guint32 (message, offset, out_in_errors, error))
            goto out;
        offset += 4;
    }

    /* Read the 'InOctets' variable */
    {
        if ((out_in_octets != NULL) && !_mbim_message_read_guint64 (message, offset, out_in_octets, error))
            goto out;
        offset += 8;
    }

    /* Read the 'InPackets' variable */
    {
        if ((out_in_packets != NULL) && !_mbim_message_read_guint64 (message, offset, out_in_packets, error))
            goto out;
        offset += 8;
    }

    /* Read the 'OutOctets' variable */
    {
        if ((out_out_octets != NULL) && !_mbim_message_read_guint64 (message, offset, out_out_octets, error))
            goto out;
        offset += 8;
    }

    /* Read the 'OutPackets' variable */
    {
        if ((out_out_packets != NULL) && !_mbim_message_read_guint64 (message, offset, out_out_packets, error))
            goto out;
        offset += 8;
    }

    /* Read the 'OutErrors' variable */
    {
        if ((out_out_errors != NULL) && !_mbim_message_read_guint32 (message, offset, out_out_errors, error))
            goto out;
        offset += 4;
    }

    /* Read the 'OutDiscards' variable */
    {
        if ((out_out_discards != NULL) && !_mbim_message_read_guint32 (message, offset, out_out_discards, error))
            goto out;
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_packet_statistics_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  InDiscards = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  InErrors = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  InOctets = ", line_prefix);
    {
        guint64 tmp;

        if (!_mbim_message_read_guint64 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%" G_GUINT64_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  InPackets = ", line_prefix);
    {
        guint64 tmp;

        if (!_mbim_message_read_guint64 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%" G_GUINT64_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  OutOctets = ", line_prefix);
    {
        guint64 tmp;

        if (!_mbim_message_read_guint64 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%" G_GUINT64_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  OutPackets = ", line_prefix);
    {
        guint64 tmp;

        if (!_mbim_message_read_guint64 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%" G_GUINT64_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  OutErrors = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  OutDiscards = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Network Idle Hint */

MbimMessage *
mbim_message_network_idle_hint_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_NETWORK_IDLE_HINT,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_network_idle_hint_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message Network Idle Hint */

MbimMessage *
mbim_message_network_idle_hint_set_new (
    MbimNetworkIdleHintState state,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_NETWORK_IDLE_HINT,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, state);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_network_idle_hint_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  State = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_NETWORK_IDLE_HINT_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_network_idle_hint_state_get_string ((MbimNetworkIdleHintState)tmp));
#elif defined __MBIM_NETWORK_IDLE_HINT_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_network_idle_hint_state_build_string_from_mask ((MbimNetworkIdleHintState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Network Idle Hint */

gboolean
mbim_message_network_idle_hint_response_parse (
    const MbimMessage *message,
    MbimNetworkIdleHintState *out_state,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'State' variable */
    {
        if (out_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_state = (MbimNetworkIdleHintState)aux;
        }
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_network_idle_hint_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  State = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_NETWORK_IDLE_HINT_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_network_idle_hint_state_get_string ((MbimNetworkIdleHintState)tmp));
#elif defined __MBIM_NETWORK_IDLE_HINT_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_network_idle_hint_state_build_string_from_mask ((MbimNetworkIdleHintState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Emergency Mode */

MbimMessage *
mbim_message_emergency_mode_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_EMERGENCY_MODE,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_emergency_mode_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message Emergency Mode */

MbimMessage *
mbim_message_emergency_mode_set_new (
    MbimEmergencyModeState state,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_EMERGENCY_MODE,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, state);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_emergency_mode_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  State = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_EMERGENCY_MODE_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_emergency_mode_state_get_string ((MbimEmergencyModeState)tmp));
#elif defined __MBIM_EMERGENCY_MODE_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_emergency_mode_state_build_string_from_mask ((MbimEmergencyModeState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Emergency Mode */

gboolean
mbim_message_emergency_mode_response_parse (
    const MbimMessage *message,
    MbimEmergencyModeState *out_state,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'State' variable */
    {
        if (out_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_state = (MbimEmergencyModeState)aux;
        }
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_emergency_mode_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  State = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_EMERGENCY_MODE_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_emergency_mode_state_get_string ((MbimEmergencyModeState)tmp));
#elif defined __MBIM_EMERGENCY_MODE_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_emergency_mode_state_build_string_from_mask ((MbimEmergencyModeState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Notification): MBIM Message Emergency Mode */

gboolean
mbim_message_emergency_mode_notification_parse (
    const MbimMessage *message,
    MbimEmergencyModeState *out_state,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_INDICATE_STATUS) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a notification");
        return FALSE;
    }

    if (!mbim_message_indicate_status_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'State' variable */
    {
        if (out_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_state = (MbimEmergencyModeState)aux;
        }
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_emergency_mode_notification_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  State = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_EMERGENCY_MODE_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_emergency_mode_state_get_string ((MbimEmergencyModeState)tmp));
#elif defined __MBIM_EMERGENCY_MODE_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_emergency_mode_state_build_string_from_mask ((MbimEmergencyModeState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message IP Packet Filters */

MbimMessage *
mbim_message_ip_packet_filters_query_new (
    guint32 session_id,
    guint32 packet_filters_count,
    const MbimPacketFilter *const *packet_filters,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_IP_PACKET_FILTERS,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);
    {
        _mbim_message_command_builder_append_guint32 (builder, session_id);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, packet_filters_count);
    }
    {
        _mbim_message_command_builder_append_mbim_packet_filter_struct_array (builder, packet_filters, packet_filters_count, TRUE);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_ip_packet_filters_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _packet_filters_count;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  SessionId = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PacketFiltersCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_packet_filters_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _packet_filters_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PacketFilters = ", line_prefix);
    {
        g_autoptr(MbimPacketFilterArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_packet_filter_struct_array (message, _packet_filters_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _packet_filters_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _packet_filters_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_packet_filter_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message IP Packet Filters */

MbimMessage *
mbim_message_ip_packet_filters_set_new (
    guint32 session_id,
    guint32 packet_filters_count,
    const MbimPacketFilter *const *packet_filters,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_IP_PACKET_FILTERS,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, session_id);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, packet_filters_count);
    }
    {
        _mbim_message_command_builder_append_mbim_packet_filter_struct_array (builder, packet_filters, packet_filters_count, TRUE);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_ip_packet_filters_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _packet_filters_count;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  SessionId = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PacketFiltersCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_packet_filters_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _packet_filters_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PacketFilters = ", line_prefix);
    {
        g_autoptr(MbimPacketFilterArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_packet_filter_struct_array (message, _packet_filters_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _packet_filters_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _packet_filters_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_packet_filter_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message IP Packet Filters */

gboolean
mbim_message_ip_packet_filters_response_parse (
    const MbimMessage *message,
    guint32 *out_session_id,
    guint32 *out_packet_filters_count,
    MbimPacketFilterArray **out_packet_filters,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    guint32 _packet_filters_count;
    MbimPacketFilter **_packet_filters = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'SessionId' variable */
    {
        if ((out_session_id != NULL) && !_mbim_message_read_guint32 (message, offset, out_session_id, error))
            goto out;
        offset += 4;
    }

    /* Read the 'PacketFiltersCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_packet_filters_count, error))
            goto out;
        if (out_packet_filters_count != NULL)
            *out_packet_filters_count = _packet_filters_count;
        offset += 4;
    }

    /* Read the 'PacketFilters' variable */
    {
        if ((out_packet_filters != NULL) && !_mbim_message_read_mbim_packet_filter_struct_array (message, _packet_filters_count, offset, TRUE, &_packet_filters, error))
            goto out;
        offset += (8 * _packet_filters_count);
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_packet_filters != NULL)
            *out_packet_filters = _packet_filters;
    } else {
        mbim_packet_filter_array_free (_packet_filters);
    }

    return success;
}

static gchar *
mbim_message_ip_packet_filters_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _packet_filters_count;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  SessionId = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PacketFiltersCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_packet_filters_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _packet_filters_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PacketFilters = ", line_prefix);
    {
        g_autoptr(MbimPacketFilterArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_packet_filter_struct_array (message, _packet_filters_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _packet_filters_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _packet_filters_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_packet_filter_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Multicarrier Providers */

MbimMessage *
mbim_message_multicarrier_providers_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_MULTICARRIER_PROVIDERS,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_multicarrier_providers_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message Multicarrier Providers */

MbimMessage *
mbim_message_multicarrier_providers_set_new (
    guint32 providers_count,
    const MbimProvider *const *providers,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_BASIC_CONNECT,
                                                 MBIM_CID_BASIC_CONNECT_MULTICARRIER_PROVIDERS,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, providers_count);
    }
    {
        _mbim_message_command_builder_append_mbim_provider_struct_array (builder, providers, providers_count, TRUE);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_multicarrier_providers_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _providers_count;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ProvidersCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_providers_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _providers_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Providers = ", line_prefix);
    {
        g_autoptr(MbimProviderArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_provider_struct_array (message, _providers_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _providers_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _providers_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_provider_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Multicarrier Providers */

gboolean
mbim_message_multicarrier_providers_response_parse (
    const MbimMessage *message,
    guint32 *out_providers_count,
    MbimProviderArray **out_providers,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    guint32 _providers_count;
    MbimProvider **_providers = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'ProvidersCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_providers_count, error))
            goto out;
        if (out_providers_count != NULL)
            *out_providers_count = _providers_count;
        offset += 4;
    }

    /* Read the 'Providers' variable */
    {
        if ((out_providers != NULL) && !_mbim_message_read_mbim_provider_struct_array (message, _providers_count, offset, TRUE, &_providers, error))
            goto out;
        offset += (8 * _providers_count);
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_providers != NULL)
            *out_providers = _providers;
    } else {
        mbim_provider_array_free (_providers);
    }

    return success;
}

static gchar *
mbim_message_multicarrier_providers_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _providers_count;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ProvidersCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_providers_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _providers_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Providers = ", line_prefix);
    {
        g_autoptr(MbimProviderArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_provider_struct_array (message, _providers_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _providers_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _providers_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_provider_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Notification): MBIM Message Multicarrier Providers */

gboolean
mbim_message_multicarrier_providers_notification_parse (
    const MbimMessage *message,
    guint32 *out_providers_count,
    MbimProviderArray **out_providers,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    guint32 _providers_count;
    MbimProvider **_providers = NULL;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_INDICATE_STATUS) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a notification");
        return FALSE;
    }

    if (!mbim_message_indicate_status_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'ProvidersCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_providers_count, error))
            goto out;
        if (out_providers_count != NULL)
            *out_providers_count = _providers_count;
        offset += 4;
    }

    /* Read the 'Providers' variable */
    {
        if ((out_providers != NULL) && !_mbim_message_read_mbim_provider_struct_array (message, _providers_count, offset, TRUE, &_providers, error))
            goto out;
        offset += (8 * _providers_count);
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_providers != NULL)
            *out_providers = _providers;
    } else {
        mbim_provider_array_free (_providers);
    }

    return success;
}

static gchar *
mbim_message_multicarrier_providers_notification_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _providers_count;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ProvidersCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_providers_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _providers_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Providers = ", line_prefix);
    {
        g_autoptr(MbimProviderArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_provider_struct_array (message, _providers_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _providers_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _providers_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_provider_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

typedef struct {
  gchar * (* query_cb)        (const MbimMessage *message, const gchar *line_prefix, GError **error);
  gchar * (* set_cb)          (const MbimMessage *message, const gchar *line_prefix, GError **error);
  gchar * (* response_cb)     (const MbimMessage *message, const gchar *line_prefix, GError **error);
  gchar * (* notification_cb) (const MbimMessage *message, const gchar *line_prefix, GError **error);
} GetPrintableCallbacks;

static const GetPrintableCallbacks get_printable_callbacks[] = {
    [MBIM_CID_BASIC_CONNECT_DEVICE_CAPS] = {
        .query_cb = mbim_message_device_caps_query_get_printable,
        .response_cb = mbim_message_device_caps_response_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_SUBSCRIBER_READY_STATUS] = {
        .query_cb = mbim_message_subscriber_ready_status_query_get_printable,
        .response_cb = mbim_message_subscriber_ready_status_response_get_printable,
        .notification_cb = mbim_message_subscriber_ready_status_notification_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_RADIO_STATE] = {
        .query_cb = mbim_message_radio_state_query_get_printable,
        .set_cb = mbim_message_radio_state_set_get_printable,
        .response_cb = mbim_message_radio_state_response_get_printable,
        .notification_cb = mbim_message_radio_state_notification_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_PIN] = {
        .query_cb = mbim_message_pin_query_get_printable,
        .set_cb = mbim_message_pin_set_get_printable,
        .response_cb = mbim_message_pin_response_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_PIN_LIST] = {
        .query_cb = mbim_message_pin_list_query_get_printable,
        .response_cb = mbim_message_pin_list_response_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_HOME_PROVIDER] = {
        .query_cb = mbim_message_home_provider_query_get_printable,
        .set_cb = mbim_message_home_provider_set_get_printable,
        .response_cb = mbim_message_home_provider_response_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_PREFERRED_PROVIDERS] = {
        .query_cb = mbim_message_preferred_providers_query_get_printable,
        .set_cb = mbim_message_preferred_providers_set_get_printable,
        .response_cb = mbim_message_preferred_providers_response_get_printable,
        .notification_cb = mbim_message_preferred_providers_notification_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_VISIBLE_PROVIDERS] = {
        .query_cb = mbim_message_visible_providers_query_get_printable,
        .response_cb = mbim_message_visible_providers_response_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_REGISTER_STATE] = {
        .query_cb = mbim_message_register_state_query_get_printable,
        .set_cb = mbim_message_register_state_set_get_printable,
        .response_cb = mbim_message_register_state_response_get_printable,
        .notification_cb = mbim_message_register_state_notification_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_SIGNAL_STATE] = {
        .query_cb = mbim_message_signal_state_query_get_printable,
        .set_cb = mbim_message_signal_state_set_get_printable,
        .response_cb = mbim_message_signal_state_response_get_printable,
        .notification_cb = mbim_message_signal_state_notification_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_PACKET_SERVICE] = {
        .query_cb = mbim_message_packet_service_query_get_printable,
        .set_cb = mbim_message_packet_service_set_get_printable,
        .response_cb = mbim_message_packet_service_response_get_printable,
        .notification_cb = mbim_message_packet_service_notification_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_CONNECT] = {
        .query_cb = mbim_message_connect_query_get_printable,
        .set_cb = mbim_message_connect_set_get_printable,
        .response_cb = mbim_message_connect_response_get_printable,
        .notification_cb = mbim_message_connect_notification_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_PROVISIONED_CONTEXTS] = {
        .query_cb = mbim_message_provisioned_contexts_query_get_printable,
        .set_cb = mbim_message_provisioned_contexts_set_get_printable,
        .response_cb = mbim_message_provisioned_contexts_response_get_printable,
        .notification_cb = mbim_message_provisioned_contexts_notification_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_SERVICE_ACTIVATION] = {
        .set_cb = mbim_message_service_activation_set_get_printable,
        .response_cb = mbim_message_service_activation_response_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_IP_CONFIGURATION] = {
        .query_cb = mbim_message_ip_configuration_query_get_printable,
        .response_cb = mbim_message_ip_configuration_response_get_printable,
        .notification_cb = mbim_message_ip_configuration_notification_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_DEVICE_SERVICES] = {
        .query_cb = mbim_message_device_services_query_get_printable,
        .response_cb = mbim_message_device_services_response_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_DEVICE_SERVICE_SUBSCRIBE_LIST] = {
        .set_cb = mbim_message_device_service_subscribe_list_set_get_printable,
        .response_cb = mbim_message_device_service_subscribe_list_response_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_PACKET_STATISTICS] = {
        .query_cb = mbim_message_packet_statistics_query_get_printable,
        .response_cb = mbim_message_packet_statistics_response_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_NETWORK_IDLE_HINT] = {
        .query_cb = mbim_message_network_idle_hint_query_get_printable,
        .set_cb = mbim_message_network_idle_hint_set_get_printable,
        .response_cb = mbim_message_network_idle_hint_response_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_EMERGENCY_MODE] = {
        .query_cb = mbim_message_emergency_mode_query_get_printable,
        .set_cb = mbim_message_emergency_mode_set_get_printable,
        .response_cb = mbim_message_emergency_mode_response_get_printable,
        .notification_cb = mbim_message_emergency_mode_notification_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_IP_PACKET_FILTERS] = {
        .query_cb = mbim_message_ip_packet_filters_query_get_printable,
        .set_cb = mbim_message_ip_packet_filters_set_get_printable,
        .response_cb = mbim_message_ip_packet_filters_response_get_printable,
    },
    [MBIM_CID_BASIC_CONNECT_MULTICARRIER_PROVIDERS] = {
        .query_cb = mbim_message_multicarrier_providers_query_get_printable,
        .set_cb = mbim_message_multicarrier_providers_set_get_printable,
        .response_cb = mbim_message_multicarrier_providers_response_get_printable,
        .notification_cb = mbim_message_multicarrier_providers_notification_get_printable,
    },
};

gchar *
__mbim_message_basic_connect_get_printable_fields (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    guint32 cid;

    switch (mbim_message_get_message_type (message)) {
        case MBIM_MESSAGE_TYPE_COMMAND: {
            cid = mbim_message_command_get_cid (message);
            if (cid < G_N_ELEMENTS (get_printable_callbacks)) {
                switch (mbim_message_command_get_command_type (message)) {
                    case MBIM_MESSAGE_COMMAND_TYPE_QUERY:
                        if (get_printable_callbacks[cid].query_cb)
                            return get_printable_callbacks[cid].query_cb (message, line_prefix, error);
                        break;
                    case MBIM_MESSAGE_COMMAND_TYPE_SET:
                        if (get_printable_callbacks[cid].set_cb)
                            return get_printable_callbacks[cid].set_cb (message, line_prefix, error);
                        break;
                    case MBIM_MESSAGE_COMMAND_TYPE_UNKNOWN:
                    default:
                        g_set_error (error,
                                     MBIM_CORE_ERROR,
                                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                                     "Invalid command type");
                        return NULL;
                }
            }
            break;
        }

        case MBIM_MESSAGE_TYPE_COMMAND_DONE:
            cid = mbim_message_command_done_get_cid (message);
            if (cid < G_N_ELEMENTS (get_printable_callbacks)) {
                if (get_printable_callbacks[cid].response_cb)
                    return get_printable_callbacks[cid].response_cb (message, line_prefix, error);
            }
            break;

        case MBIM_MESSAGE_TYPE_INDICATE_STATUS:
            cid = mbim_message_indicate_status_get_cid (message);
            if (cid < G_N_ELEMENTS (get_printable_callbacks)) {
                if (get_printable_callbacks[cid].notification_cb)
                    return get_printable_callbacks[cid].notification_cb (message, line_prefix, error);
            }
            break;

        case MBIM_MESSAGE_TYPE_OPEN: 
        case MBIM_MESSAGE_TYPE_CLOSE: 
        case MBIM_MESSAGE_TYPE_INVALID: 
        case MBIM_MESSAGE_TYPE_HOST_ERROR: 
        case MBIM_MESSAGE_TYPE_OPEN_DONE: 
        case MBIM_MESSAGE_TYPE_CLOSE_DONE: 
        case MBIM_MESSAGE_TYPE_FUNCTION_ERROR: 
        default:
            g_set_error (error,
                         MBIM_CORE_ERROR,
                         MBIM_CORE_ERROR_INVALID_MESSAGE,
                         "No contents expected in this message type");
            return NULL;
    }

    g_set_error (error,
                 MBIM_CORE_ERROR,
                 MBIM_CORE_ERROR_INVALID_MESSAGE,
                 "Unknown contents");
    return NULL;
}
