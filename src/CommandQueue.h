/*
 * Author: doe300
 *
 * See the file "LICENSE" for the full license governing this code.
 */
#ifndef VC4CL_COMMANDQUEUE_H
#define VC4CL_COMMANDQUEUE_H

#include "Context.h"

namespace vc4cl
{

	class Event;

	class CommandQueue : public Object<_cl_command_queue, CL_INVALID_COMMAND_QUEUE>, public HasContext
	{
	public:
		CommandQueue(Context* context, bool outOfOrderExecution, bool profiling);
		~CommandQueue() override;

		CHECK_RETURN cl_int getInfo(cl_command_queue_info param_name, size_t param_value_size, void* param_value, size_t* param_value_size_ret) const;

		CHECK_RETURN cl_int waitForWaitListFinish(const cl_event* waitList, cl_uint numEvents) const;
		CHECK_RETURN cl_int enqueueEvent(Event* event);
		cl_int setProperties(cl_command_queue_properties properties, bool enable);

		cl_int flush();
		cl_int finish();

		bool isProfilingEnabled() const;
	private:

		//properties
		bool outOfOrderExecution;
		bool profiling;
	};

} /* namespace vc4cl */

#endif /* VC4CL_COMMANDQUEUE_H */
